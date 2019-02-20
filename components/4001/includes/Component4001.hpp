/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4001Component
*/

#ifndef COMPONENT4001_HPP_
    #define COMPONENT4001_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace nts {
    class Component4001 : public nts::AbstractComponent {
        public:
            Component4001() = default;
            Component4001(const Component4001 &) = default;
            nts::Tristate compute(std::size_t pin = 1);
            void dump() const;
            std::unique_ptr<nts::IComponent> clone();
    };
}

#endif /* !COMPONENT4001_HPP_ */
