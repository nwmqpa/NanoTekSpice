/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4030Component
*/

#include "Utils.hpp"
#include "Component4030.hpp"

nts::Tristate nts::Component4030::compute(std::size_t pin)
{
    nts::debug << "Computing PIN" << pin << std::endl;
    return nts::UNDEFINED;
}

void nts::Component4030::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::debug << "Set link between PIN" << pin << " and PIN" << otherPin << std::endl;
}

void nts::Component4030::dump() const
{
    nts::debug << "Dump of component" << std::endl;
}

std::unique_ptr<nts::IComponent> nts::Component4030::clone()
{
    return std::make_unique<nts::Component4030>(*this);
}
