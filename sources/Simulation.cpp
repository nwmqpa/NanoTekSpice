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
}

void Simulation::run()
{}

void Simulation::exit()
{}

void Simulation::display()
{}

void Simulation::simulate()
{}

void Simulation::loop()
{}

void Simulation::dump()
{
//    std::for_each(_components.begin(), _components.end(), []() {});
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
