/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** DummyComponent
*/

#include "Utils.hpp"
#include "DummyComponent.hpp"

nts::Tristate nts::DummyComponent::compute(std::size_t pin)
{
    nts::debug << "Computing PIN" << pin << std::endl;
    return nts::UNDEFINED;
}

void nts::DummyComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::debug << "Set link between PIN" << pin << " and PIN" << otherPin << std::endl;
}

void nts::DummyComponent::dump() const
{
    nts::debug << "Dump of component" << std::endl;
}

std::unique_ptr<nts::IComponent> nts::DummyComponent::clone()
{
    return std::make_unique<nts::DummyComponent>(*this);
}
