/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Tristate
*/

#ifndef TRISTATE_HPP_
    #define TRISTATE_HPP_

#include <iostream>
#include <vector>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        FALSE = false,
        TRUE = true
    };
}

nts::Tristate operator&(const nts::Tristate &lho, const nts::Tristate &rho);
nts::Tristate operator|(const nts::Tristate &lho, const nts::Tristate &rho);
nts::Tristate operator^(const nts::Tristate &lho, const nts::Tristate &rho);
nts::Tristate operator~(const nts::Tristate &lho);
std::ostream &operator<<(std::ostream &stream, const nts::Tristate &rho);
std::ostream &operator<<(std::ostream &stream, const std::vector<nts::Tristate *> &rho);


#endif /* !TRISTATE_HPP_ */
