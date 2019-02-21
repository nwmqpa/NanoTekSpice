/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#ifndef COMPONENTNOR_HPP_
    #define COMPONENTNOR_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace nts {
    class ComponentNOR : public nts::AbstractComponent {
        public:
            ComponentNOR();
            ComponentNOR(const ComponentNOR &);
            nts::Tristate compute(std::size_t pin = 1) final;
            void dump() const;
            std::unique_ptr<nts::IComponent> clone(const std::string &value);
    };
}

#endif /* !COMPONENT4071_HPP_ */
