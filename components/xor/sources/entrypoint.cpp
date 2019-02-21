/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** entrypoint
*/

#include "ComponentXOR.hpp"
#include "ComponentFactory.hpp"

extern "C" void entrypoint(nts::ComponentFactory *factory)
{
    factory->registerComponent(new nts::ComponentXOR(), std::string("xor"));
}
