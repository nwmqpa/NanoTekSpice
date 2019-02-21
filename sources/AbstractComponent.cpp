/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** AbstractComponent
*/

#include <iostream>
#include "AbstractComponent.hpp"
#include "ComponentFactory.hpp"

nts::AbstractComponent::~AbstractComponent()
{
}

nts::Tristate nts::AbstractComponent::compute(std::size_t pin)
{
    for (auto &&gate : gatesToUpdate) {
        gate->compute();
    }
    return *pins.at(pin);
}

void nts::AbstractComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pins.at(pin) != nullptr) {
        (static_cast<nts::AbstractComponent&> (other)).pins.at(otherPin) = pins.at(pin);
        return;
    }
    if ((static_cast<nts::AbstractComponent&> (other)).pins.at(otherPin) != nullptr) {
        pins.at(pin) = (static_cast<nts::AbstractComponent&> (other)).pins.at(otherPin);
        return;
    }
    nts::Tristate *tristate = new nts::Tristate;
    pins.at(pin) = tristate;
    (static_cast<nts::AbstractComponent&> (other)).pins.at(otherPin) = tristate;
    ComponentFactory::getFactory()->registerPin(tristate);
}