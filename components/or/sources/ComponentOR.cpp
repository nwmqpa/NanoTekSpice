/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentOR.hpp"

nts::ComponentOR::ComponentOR()
{
}

nts::ComponentOR::ComponentOR(const ComponentOR &value)
{
    (void) value;
}

nts::Tristate nts::ComponentOR::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr && pins.at(2) != nullptr && pins.at(3) != nullptr)
        *pins.at(3) = *pins.at(1) | *pins.at(2);
    return *pins.at(pin);
}

void nts::ComponentOR::dump() const
{
    nts::debug << "Dump of component OR" << std::endl;
}

std::unique_ptr<nts::IComponent> nts::ComponentOR::clone(const std::string &value)
{
    auto component = std::make_unique<nts::ComponentOR>(*this);
    (void) value;
    component.get()->pins.resize(4);
    return component;
}
