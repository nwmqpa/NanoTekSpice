/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "Component4071.hpp"

nts::Tristate nts::Component4071::compute(std::size_t pin)
{
    nts::debug << "Computing PIN" << pin << std::endl;
    return nts::UNDEFINED;
}

void nts::Component4071::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::debug << "Set link between PIN" << pin << " and PIN" << otherPin << std::endl;
}

void nts::Component4071::dump() const
{
    nts::debug << "Dump of component" << std::endl;
}

std::unique_ptr<nts::IComponent> nts::Component4071::clone()
{
    return std::make_unique<nts::Component4071>(*this);
}
