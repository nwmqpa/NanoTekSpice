/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Tristate
*/

#ifndef TRISTATE_HPP_
    #define TRISTATE_HPP_

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

#endif /* !TRISTATE_HPP_ */
