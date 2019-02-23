/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentNOR.hpp"

nts::ComponentNOR::ComponentNOR()
{
    this->setName(std::string("nor"));
}

nts::Tristate nts::ComponentNOR::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr && pins.at(2) != nullptr && pins.at(3) != nullptr)
        *pins.at(3) = ~(*pins.at(1) | *pins.at(2));
    return *pins.at(pin);
}

std::unique_ptr<nts::IComponent> nts::ComponentNOR::clone(const std::string &value)
{
    auto component = std::make_unique<nts::ComponentNOR>(*this);
    (void) value;
    component.get()->pins.assign(4, nullptr);
    return component;
}
