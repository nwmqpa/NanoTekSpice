/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** ComponentOutput implementation
*/

#include "Utils.hpp"
#include "ComponentOutput.hpp"

nts::ComponentOutput::ComponentOutput()
{
    pins.resize(1);
}

nts::ComponentOutput::ComponentOutput(const ComponentOutput &value)
{
    (void) value;
}

nts::Tristate nts::ComponentOutput::compute(std::size_t pin)
{
    return *pins.at(pin);
}

void nts::ComponentOutput::dump() const
{
    nts::debug << "Dump of component Output" << std::endl;
}

std::unique_ptr<nts::IComponent> nts::ComponentOutput::clone(const std::string &value)
{
    auto component = std::make_unique<nts::ComponentOutput>(*this);
    (void) value;
    component.get()->pins.resize(1);
    return component;
}
