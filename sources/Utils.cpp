/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Utils
*/

#include "Utils.hpp"

nts::Debug nts::debug = nts::Debug();

nts::Debug& operator<<(nts::Debug &s, std::ostream& (*f)(std::ostream &))
{
#ifdef DEBUG
    f(std::cout);
#endif
    return s;
}

nts::Debug& operator<<(nts::Debug &s, std::ostream& (*f)(std::ios &))
{
#ifdef DEBUG
    f(std::cout);
#endif
    return s;
}

nts::Debug& operator<<(nts::Debug &s, std::ostream& (*f)(std::ios_base &))
{
#ifdef DEBUG
    f(std::cout);
#endif
    return s;
}