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

void Simulation::setupChip(const std::string &line, std::string &type, std::string &name)
{
    size_t x;
    size_t y;

    x = line.find_first_of(" ");
    y = line.find_first_of("\t");
    if ((y < x) && (y != std::string::npos))
        x = y;
    type.assign(line.substr(0, x));
    x = line.find_last_of(" ");
    y = line.find_last_of("\t");
    if ((y > x) && (y != std::string::npos))
        x = y;
    name.assign(line.substr(x + 1, std::string::npos));
}

void Simulation::setup()
{
    _parser.parseFile("or_gate3.nts");
    std::vector<std::string> content = _parser.getContent();
    std::string type;
    std::string name;

    for (std::string line : content) {
        if (!line.compare(".links:"))
            break;
        if (line.find(" ") == std::string::npos && line.find("\t") == std::string::npos)
            continue;
        setupChip(line, type, name);
        if (type.compare("input"))
            _input.push_back(name);
        if (type.compare("output"))
            _output.push_back(name);
        nts::debug << "type=" << type << " name=" << name << std::endl;
        _components[name] = std::move(nts::ComponentFactory::getFactory()->createComponent(type, ""));
    }
}

void Simulation::run()
{
    nts::debug << "Simulation is running." << std::endl;
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
