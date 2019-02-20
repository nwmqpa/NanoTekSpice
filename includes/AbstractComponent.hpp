/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** AbstractComponent
*/

#ifndef ABSTRACTCOMPONENT_HPP_
    #define ABSTRACTCOMPONENT_HPP_

#include <vector>
#include <map>
#include <queue>
#include "IComponent.hpp"

namespace nts {
    class AbstractComponent : public nts::IComponent {
        public:
            ~AbstractComponent();
            nts::Tristate compute(std::size_t pin = 1) final;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;

        protected:
            std::vector<nts::Tristate *> pins;
            std::map<std::string, nts::IComponent *> gates;
            std::queue<nts::IComponent *> gatesToUpdate;

    };
}

#endif /* !ABSTRACTCOMPONENT_HPP_ */
