/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** ComponentInput header
*/

#ifndef COMPONENTINPUT_HPP_
    #define COMPONENTINPUT_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace nts {
    class ComponentInput : public nts::AbstractComponent {
        public:
            ComponentInput();
            std::unique_ptr<nts::IComponent> clone(const std::string &);
            void setInput(nts::Tristate value);
    };
}

#endif /* !COMPONENTINPUT_HPP_ */
