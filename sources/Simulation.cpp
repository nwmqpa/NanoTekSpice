/*
** EPITECH PROJECT, 2019
** Simulation.cpp
** File description:
** Simulation implementation
*/

#include "Simulation.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

void Simulation::setup()
{
    _components.push_back(std::move(nts::ComponentFactory::getFactory()->createComponent("4001", "")));
    _components.push_back(std::move(nts::ComponentFactory::getFactory()->createComponent("4011", "")));
    _components.push_back(std::move(nts::ComponentFactory::getFactory()->createComponent("4030", "")));
    _components.push_back(std::move(nts::ComponentFactory::getFactory()->createComponent("4071", "")));
    _components.push_back(std::move(nts::ComponentFactory::getFactory()->createComponent("and", "")));
    _components.push_back(std::move(nts::ComponentFactory::getFactory()->createComponent("nand", "")));
    _components.push_back(std::move(nts::ComponentFactory::getFactory()->createComponent("nor", "")));
    _components.push_back(std::move(nts::ComponentFactory::getFactory()->createComponent("not", "")));
    _components.push_back(std::move(nts::ComponentFactory::getFactory()->createComponent("or", "")));
    _components.push_back(std::move(nts::ComponentFactory::getFactory()->createComponent("xnor", "")));
    _components.push_back(std::move(nts::ComponentFactory::getFactory()->createComponent("xor", "")));
}

void Simulation::run()
{
    std::cout << "Simulation is running." << std::endl;
    this->simulate();
}

void Simulation::exit()
{
    for (int i = _components.size(); i; i--)
        _components.pop_back();
}

void Simulation::display()
{}

void Simulation::simulate()
{
    for (auto &&components : _components)
        components->compute();
}

void Simulation::loop()
{}

void Simulation::dump()
{
    for (auto &&components : _components)
        components->dump();
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
