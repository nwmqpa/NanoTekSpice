/*
** EPITECH PROJECT, 2019
** Simulation.cpp
** File description:
** Simulation implementation
*/

#include "Simulation.hpp"
#include "Utils.hpp"
#include "AbstractComponent.hpp"
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
    _parser.parseFile("file.nts");

    setupChipsets();
    setupLinks();
    _isRunning = false;
}

void Simulation::actionChoice(const std::string &line, std::smatch match)
{
    if (!line.compare("dump"))
        dump();
    else if (!line.compare("exit"))
        exit();
    else if (!line.compare("simulate"))
        simulate();
    else if (!line.compare("loop"))
        loop();
    else if (!line.compare("display"))
        display();
    else
        setInput(match[1], match[2]);
}

void Simulation::run()
{
    std::regex reg("(?:([a-zA-Z0-9_]+)=([01Uu]))|(dump|exit|simulate|loop|display)");
    std::smatch match;

    nts::debug << "Simulation is running." << std::endl;
    while (!_isRunning) {
        getUserInput();
        if (std::regex_match(_lastInput, match, reg))
            actionChoice(match[0], match);
        else
            std::cerr << program_invocation_short_name << ": " << _lastInput << ": invalid option." << std::endl;
    }
}

void Simulation::exit()
{
    for (auto i = _input.begin(); i != _input.end();)
        i = _input.erase(i);
    for (auto i = _output.begin(); i != _output.end();)
        i = _output.erase(i);
    for (auto i = _components.begin(); i != _components.end();)
        i = _components.erase(i);
    _isRunning = true;
}

void Simulation::display()
{
    for (auto i = _output.begin(); i != _output.end(); i++) {
        auto cursor = i->first;
        std::cout << cursor << "=" << static_cast<nts::AbstractComponent *>(_output[cursor].get())->getOutput() << std::endl;
    }
}

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

void Simulation::setInput(const std::string &name, const std::string &value)
{
    if (!value.compare("0"))
        static_cast<nts::AbstractComponent *>(getComponent(name))->setPinAt(1, nts::Tristate::FALSE);
    else if (!value.compare("1"))
        static_cast<nts::AbstractComponent *>(getComponent(name))->setPinAt(1, nts::Tristate::TRUE);
    else
        static_cast<nts::AbstractComponent *>(getComponent(name))->setPinAt(1, nts::Tristate::UNDEFINED);
}

void Simulation::getUserInput()
{
    std::cout << "> ";
    std::getline(std::cin, _lastInput);
}
