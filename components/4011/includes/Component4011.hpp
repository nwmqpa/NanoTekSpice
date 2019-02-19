/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4011Component
*/

#ifndef COMPONENT4011_HPP_
    #define COMPONENT4011_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace nts {
    class Component4011 : public nts::AbstractComponent {
        public:
            Component4011() = default;
            Component4011(const Component4011 &) = default;
            nts::Tristate compute(std::size_t pin = 1);
            void dump() const;
            std::unique_ptr<nts::IComponent> clone();
    };
}

#endif /* !COMPONENT4011_HPP_ */
