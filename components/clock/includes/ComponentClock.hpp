/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#ifndef COMPONENTClock_HPP_
    #define COMPONENTClock_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace nts {
    class ComponentClock : public nts::AbstractComponent {
        public:
            ComponentClock();
            nts::Tristate compute(std::size_t pin = 1) final;
            std::unique_ptr<nts::IComponent> clone(const std::string &);
    };
}

#endif /* !COMPONENT4071_HPP_ */
