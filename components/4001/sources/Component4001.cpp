/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4001Component
*/

#include "Utils.hpp"
#include "Component4001.hpp"

nts::Tristate nts::Component4001::compute(std::size_t pin)
{
    nts::debug << "Computing PIN" << pin << std::endl;
    return nts::UNDEFINED;
}

void nts::Component4001::dump() const
{
    nts::debug << "Dump of component" << std::endl;
}

std::unique_ptr<nts::IComponent> nts::Component4001::clone()
{
    return std::make_unique<nts::Component4001>(*this);
}
