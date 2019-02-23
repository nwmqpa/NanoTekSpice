/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentTrue.hpp"

nts::ComponentTrue::ComponentTrue()
{
    this->setName(std::string("true"));
}

nts::Tristate nts::ComponentTrue::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr)
        *pins.at(1) = nts::Tristate::TRUE;
    return *pins.at(pin);
}

std::unique_ptr<nts::IComponent> nts::ComponentTrue::clone(const std::string &value)
{
    auto component = std::make_unique<nts::ComponentTrue>(*this);
    (void) value;
    component.get()->pins.resize(2);
    return component;
}
