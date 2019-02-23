/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#ifndef COMPONENTXNOR_HPP_
    #define COMPONENTXNOR_HPP_

#include "AbstractComponent.hpp"

namespace nts {
    class ComponentXNOR : public nts::AbstractComponent {
        public:
            ComponentXNOR();
            nts::Tristate compute(std::size_t pin = 1) final;
            std::unique_ptr<nts::IComponent> clone(const std::string &);
    };
}

#endif /* !COMPONENT4071_HPP_ */
