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
            AbstractComponent();
            AbstractComponent(const AbstractComponent &);
            nts::Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void setPinAt(std::size_t pin, nts::Tristate value);
            void dump() const;
            nts::Tristate getOutput() const;

        protected:
            void recomputeGraph(nts::Tristate *oldPtr, nts::Tristate *newPtr);
            void setName(const std::string &name);
            std::vector<nts::Tristate *> pins;
            std::vector<std::unique_ptr<nts::IComponent>> gatesToUpdate;
        private:
            std::string name;

    };
}

#endif /* !ABSTRACTCOMPONENT_HPP_ */
