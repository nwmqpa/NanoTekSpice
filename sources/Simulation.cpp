/*
** EPITECH PROJECT, 2019
** Simulation.cpp
** File description:
** Simulation implementation
*/

#include "Simulation.hpp"
#include "Utils.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

nts::IComponent *Simulation::getComponent(const std::string &name)
{
    for (auto i = _components.begin(); i != _components.end(); i++) {
        auto cursor = i->first;
        if (cursor == name)
            return _components[cursor].get();
    }
    for (auto i = _input.begin(); i != _input.end(); i++) {
        auto cursor = i->first;
        if (cursor == name)
            return _input[cursor].get();
    }
    for (auto i = _output.begin(); i != _output.end(); i++) {
        auto cursor = i->first;
        if (cursor == name)
            return _output[cursor].get();
    }
    return nullptr;
}

void Simulation::setupChipsets()
{
    auto chipsets = _parser.getChipsets();

    for (auto [type, name, param] : chipsets) {
        if (!type.compare("input"))
            _input[name] = std::move(nts::ComponentFactory::getFactory()->createComponent(type, param));
        else if (!type.compare("output"))
            _output[name] = std::move(nts::ComponentFactory::getFactory()->createComponent(type, param));
        else
            _components[name] = std::move(nts::ComponentFactory::getFactory()->createComponent(type, param));
    }
}

void Simulation::setupLinks()
{
    auto links = _parser.getLinks();

    for (auto [c1, p1, c2, p2] : links) {
        getComponent(c1)->setLink(std::stoi(p1), *getComponent(c2), std::stoi(p2));
    }
}

void Simulation::setup()
{
    _parser.parseFile("or_gate3.nts");

    setupChipsets();
    setupLinks();
}

void Simulation::run()
{
    nts::debug << "Simulation is running." << std::endl;
    this->dump();
    this->simulate();
}

void Simulation::exit()
{
    for (auto i = _input.begin(); i != _input.end();)
        i = _input.erase(i);
    for (auto i = _output.begin(); i != _output.end();)
        i = _output.erase(i);
    for (auto i = _components.begin(); i != _components.end();)
        i = _components.erase(i);
}

void Simulation::display()
{}

void Simulation::simulate()
{
    for (auto i = _components.begin(); i != _components.end(); i++) {
        auto cursor = i->first;
        _components[cursor]->compute();
    }
}

void Simulation::loop()
{}

void Simulation::dump()
{
    for (auto i = _components.begin(); i != _components.end(); i++) {
        auto cursor = i->first;
        _components[cursor]->dump();
    }
}

void Simulation::setInput(const std::string &variable, const std::string &value)
{
    (void) variable;
    (void) value;
}

void Simulation::getUserInput()
{
    std::cout << "> ";
    std::getline(std::cin, _lastInput);
}
