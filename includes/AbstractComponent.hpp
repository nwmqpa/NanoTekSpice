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
#include <list>
#include "IComponent.hpp"

namespace nts {
    class AbstractComponent : public nts::IComponent {
        public:
            ~AbstractComponent();
            nts::Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void setPinAt(std::size_t pin, nts::Tristate value);
            nts::Tristate getOutput() const;

        protected:
            void recomputeGraph(nts::Tristate *oldPtr, nts::Tristate *newPtr);
            std::vector<nts::Tristate *> pins;
            std::vector<std::unique_ptr<nts::IComponent>> gatesToUpdate;

    };
}

#endif /* !ABSTRACTCOMPONENT_HPP_ */
