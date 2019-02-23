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
    this->setName(std::string("output"));
}

nts::Tristate nts::ComponentOutput::compute(std::size_t pin)
{
    return *pins.at(pin);
}

std::unique_ptr<nts::IComponent> nts::ComponentOutput::clone(const std::string &value)
{
    auto component = std::make_unique<nts::ComponentOutput>(*this);
    (void) value;
    component.get()->pins.resize(2);
    return component;
}
