/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** entrypoint
*/

#include "Component4001.hpp"
#include "ComponentFactory.hpp"

extern "C" void entrypoint(nts::ComponentFactory *factory)
{
    factory->registerComponent(new nts::Component4001(), std::string("4001"));
}
