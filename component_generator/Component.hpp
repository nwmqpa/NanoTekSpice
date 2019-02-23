/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** {0}Component
*/

#ifndef COMPONENT{1}_HPP_
    #define COMPONENT{1}_HPP_

#include <vector>
#include "AbstractComponent.hpp"

namespace nts {{
    class Component{0} : public nts::AbstractComponent {{
        public:
            Component{0}();
            std::unique_ptr<nts::IComponent> clone(const std::string &value);
    }};
}}

#endif /* !COMPONENT{1}_HPP_ */
