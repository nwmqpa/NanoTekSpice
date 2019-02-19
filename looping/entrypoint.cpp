/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** entrypoint
*/

#include "Component{0}.hpp"
#include "ComponentFactory.hpp"

extern "C" void entrypoint(nts::ComponentFactory *factory)
{{
    factory->registerComponent(new nts::Component{0}(), std::string("{1}"));
}}
