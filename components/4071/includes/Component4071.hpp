/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#ifndef COMPONENT4071_HPP_
    #define COMPONENT4071_HPP_

#include <vector>
#include "IComponent.hpp"

namespace nts {
    class Component4071 : public nts::IComponent {
        public:
            Component4071() = default;
            ~Component4071() = default;
            Component4071(const Component4071 &) = default;
            nts::Tristate compute(std::size_t pin = 1);
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            void dump() const;
            std::unique_ptr<nts::IComponent> clone();
    };
}

#endif /* !COMPONENT4071_HPP_ */
