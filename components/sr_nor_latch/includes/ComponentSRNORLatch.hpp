/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#ifndef COMPONENTSRNORLatch_HPP_
    #define COMPONENTSRNORLatch_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace nts {
    class ComponentSRNORLatch : public nts::AbstractComponent {
        public:
            ComponentSRNORLatch();
            nts::Tristate compute(std::size_t pin = 1) final;
            std::unique_ptr<nts::IComponent> clone(const std::string &);
        private:
            nts::Tristate local;
    };
}

#endif /* !COMPONENT4071_HPP_ */
