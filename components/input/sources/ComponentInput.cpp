/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** ComponentInput implementation
*/

#include "Utils.hpp"
#include "ComponentInput.hpp"

nts::ComponentInput::ComponentInput()
{
}

nts::ComponentInput::ComponentInput(const ComponentInput &value)
{
    (void) value;
}

nts::Tristate nts::ComponentInput::compute(std::size_t pin)
{
    return *pins.at(pin);
}

void nts::ComponentInput::dump() const
{
    nts::debug << "Dump of component Input" << std::endl;
}

std::unique_ptr<nts::IComponent> nts::ComponentInput::clone(const std::string &value)
{
    auto component = std::make_unique<nts::ComponentInput>(*this);
    (void) value;
    component.get()->pins.resize(2);
    return component;
}
