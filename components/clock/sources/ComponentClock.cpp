/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentClock.hpp"

nts::ComponentClock::ComponentClock()
{
    this->setName(std::string("clock"));
}

nts::Tristate nts::ComponentClock::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr)
        *pins.at(1) = ~(*pins.at(1));
    return *pins.at(pin);
}

std::unique_ptr<nts::IComponent> nts::ComponentClock::clone(const std::string &value)
{
    auto component = std::make_unique<nts::ComponentClock>(*this);
    (void) value;
    component.get()->pins.resize(2);
    return component;
}
