/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4011Component
*/

#include "Utils.hpp"
#include "Component4011.hpp"

nts::Tristate nts::Component4011::compute(std::size_t pin)
{
    nts::debug << "Computing PIN" << pin << std::endl;
    return nts::UNDEFINED;
}

void nts::Component4011::dump() const
{
    nts::debug << "Dump of component" << std::endl;
}

std::unique_ptr<nts::IComponent> nts::Component4011::clone()
{
    return std::make_unique<nts::Component4011>(*this);
}
