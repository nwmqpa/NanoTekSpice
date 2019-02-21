/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentAND.hpp"

nts::ComponentAND::ComponentAND()
{
}

nts::ComponentAND::ComponentAND(const ComponentAND &value)
{
    (void) value;
}

nts::Tristate nts::ComponentAND::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr && pins.at(2) != nullptr && pins.at(3) != nullptr)
        *pins.at(3) = *pins.at(1) & *pins.at(2);
    return *pins.at(pin);
}

void nts::ComponentAND::dump() const
{
    nts::debug << "Dump of component AND" << std::endl;
}

std::unique_ptr<nts::IComponent> nts::ComponentAND::clone(const std::string &value)
{
    auto component = std::make_unique<nts::ComponentAND>(*this);
    (void) value;
    pins.resize(4);
    return component;
}
