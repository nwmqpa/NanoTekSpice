/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Utils
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_

#include <iostream>

namespace nts {
    struct Debug { };

    extern nts::Debug debug;
}

template<typename T>
nts::Debug& operator<<(nts::Debug &s, const T &x)
{
#   ifdef DEBUG
    std::cout << x;
#   endif
  return s;
}

nts::Debug& operator<<(nts::Debug &s, std::ostream& (*f)(std::ostream &));
nts::Debug& operator<<(nts::Debug &s, std::ostream& (*f)(std::ios &));
nts::Debug& operator<<(nts::Debug &s, std::ostream& (*f)(std::ios_base &));

#endif /* !UTILS_HPP_ */
