/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Tristate
*/

#include "Tristate.hpp"

nts::Tristate operator&(const nts::Tristate &lho, const nts::Tristate &rho)
{
    if (lho == nts::Tristate::UNDEFINED || rho == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (lho == rho)
        return rho;
    return nts::Tristate::FALSE;
}

nts::Tristate operator|(const nts::Tristate &lho, const nts::Tristate &rho)
{
    if (lho == nts::Tristate::UNDEFINED || rho == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (lho == nts::Tristate::FALSE)
        return rho;
    return lho;
}

nts::Tristate operator^(const nts::Tristate &lho, const nts::Tristate &rho)
{
    return (~lho & rho) | (lho & ~rho);
}

nts::Tristate operator~(const nts::Tristate &lho)
{
    if (lho == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (lho == nts::Tristate::TRUE)
        return nts::Tristate::FALSE;
    return nts::Tristate::TRUE;
}

std::ostream &operator<<(std::ostream &stream, const nts::Tristate &rho)
{
    if (rho == nts::Tristate::UNDEFINED)
        stream << "U";
    else if (rho == nts::Tristate::TRUE)
        stream << "1";
    else
        stream << "0";
    return stream;
}