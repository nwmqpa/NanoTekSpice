/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentFalse.hpp"

nts::ComponentFalse::ComponentFalse()
{
    this->setName(std::string("false"));
}

nts::Tristate nts::ComponentFalse::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr)
        *pins.at(1) = nts::Tristate::FALSE;
    return *pins.at(pin);
}

std::unique_ptr<nts::IComponent> nts::ComponentFalse::clone(const std::string &value)
{
    auto component = std::make_unique<nts::ComponentFalse>(*this);
    (void) value;
    component.get()->pins.resize(2);
    return component;
}
