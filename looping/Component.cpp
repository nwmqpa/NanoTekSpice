/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** {0}Component
*/

#include "Utils.hpp"
#include "Component{0}.hpp"
#include "ComponentFactory.hpp"

void nts::Component{0}::dump() const
{{
    nts::debug << "Dump of component {0}" << std::endl;
}}

std::unique_ptr<nts::IComponent> nts::Component{0}::clone()
{{
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Component{0}>(*this);
    auto factory = nts::ComponentFactory::getFactory();
    {1}
    return component;
}}
