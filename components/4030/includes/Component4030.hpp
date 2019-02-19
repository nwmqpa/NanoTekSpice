/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4030Component
*/

#ifndef COMPONENT4030_HPP_
    #define COMPONENT4030_HPP_

#include <vector>
#include "IComponent.hpp"

namespace nts {
    class Component4030 : public nts::IComponent {
        public:
            Component4030() = default;
            ~Component4030() = default;
            Component4030(const Component4030 &) = default;
            nts::Tristate compute(std::size_t pin = 1);
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            void dump() const;
            std::unique_ptr<nts::IComponent> clone();
    };
}

#endif /* !COMPONENT4030_HPP_ */
