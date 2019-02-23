/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** AbstractComponent
*/

#include <iostream>
#include "Utils.hpp"
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
    nts::AbstractComponent &otherComponent = (static_cast<nts::AbstractComponent &> (other));
    if (otherComponent.pins.at(otherPin) != nullptr && pins.at(pin) != nullptr) {
        otherComponent.recomputeGraph(otherComponent.pins.at(otherPin), pins.at(pin));
    }
    if (pins.at(pin) != nullptr) {
        otherComponent.pins.at(otherPin) = pins.at(pin);
        return;
    }
    if (otherComponent.pins.at(otherPin) != nullptr) {
        pins.at(pin) = otherComponent.pins.at(otherPin);
        return;
    }
    nts::Tristate *tristate = new nts::Tristate;
    *tristate = nts::Tristate::FALSE;
    pins.at(pin) = tristate;
    otherComponent.pins.at(otherPin) = tristate;
    ComponentFactory::getFactory()->registerPin(tristate);
}

void nts::AbstractComponent::setPinAt(std::size_t pin, nts::Tristate value)
{
    *(pins.at(pin)) = value;
}

nts::Tristate nts::AbstractComponent::getOutput() const
{
    return *(pins.at(1));
}

void nts::AbstractComponent::recomputeGraph(nts::Tristate *oldPtr, nts::Tristate *newPtr)
{
    for (std::size_t i = 0; i < pins.size(); i++) {
        if (pins.at(i) == oldPtr)
            pins.at(i) = newPtr;
    }
    for (auto &&gate : gatesToUpdate) {
        (static_cast<nts::AbstractComponent *> (gate.get()))->recomputeGraph(oldPtr, newPtr);
    }
}