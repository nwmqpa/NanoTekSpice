/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** ComponentOutput header
*/

#ifndef COMPONENTOUTPUT_HPP_
    #define COMPONENTOUTPUT_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace nts {
    class ComponentOutput : public nts::AbstractComponent {
        public:
            ComponentOutput();
            nts::Tristate compute(std::size_t pin = 1) final;
            std::unique_ptr<nts::IComponent> clone(const std::string &);
    };
}

#endif /* !COMPONENTOUTPUT_HPP_ */
