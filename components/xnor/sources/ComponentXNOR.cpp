/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentXNOR.hpp"

nts::ComponentXNOR::ComponentXNOR()
{
    this->setName(std::string("xnor"));
}

nts::Tristate nts::ComponentXNOR::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr && pins.at(2) != nullptr && pins.at(3) != nullptr)
        *pins.at(3) = ~(*pins.at(1) ^ *pins.at(2));
    return *pins.at(pin);
}

std::unique_ptr<nts::IComponent> nts::ComponentXNOR::clone(const std::string &value)
{
    auto component = std::make_unique<nts::ComponentXNOR>(*this);
    (void) value;
    component.get()->pins.resize(4);
    return component;
}
