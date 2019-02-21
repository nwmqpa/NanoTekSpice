/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** entrypoint
*/

#include "ComponentXNOR.hpp"
#include "ComponentFactory.hpp"

extern "C" void entrypoint(nts::ComponentFactory *factory)
{
    factory->registerComponent(new nts::ComponentXNOR(), std::string("xnor"));
}
