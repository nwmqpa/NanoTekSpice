/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** {0}Component
*/

#include "Utils.hpp"
#include "Component{0}.hpp"
#include "ComponentFactory.hpp"

nts::Component{0}::Component{0}()
{{
    this->setName(std::string("{2}"));
}}

std::unique_ptr<nts::IComponent> nts::Component{0}::clone(const std::string &value)
{{
    auto component = std::make_unique<nts::Component{0}>(*this);
    auto factory = nts::ComponentFactory::getFactory();
    (void) value;
{1}
    return component;
}}
