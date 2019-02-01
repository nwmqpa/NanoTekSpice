/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** DummyComponent
*/

#ifndef DUMMYCOMPONENT_HPP_
    #define DUMMYCOMPONENT_HPP_

#include <vector>
#include "IComponent.hpp"

namespace nts {
    class DummyComponent : public nts::IComponent {
        public:
            DummyComponent() = default;
            ~DummyComponent() = default;
            DummyComponent(const DummyComponent &) = default;
            nts::Tristate compute(std::size_t pin = 1);
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            void dump() const;
            std::unique_ptr<nts::IComponent> clone();

        private:
            nts::Tristate pins[12];
    };
}

#endif /* !DUMMYCOMPONENT_HPP_ */
