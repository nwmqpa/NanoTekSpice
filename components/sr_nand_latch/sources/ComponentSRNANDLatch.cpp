/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentSRNANDLatch.hpp"

nts::ComponentSRNANDLatch::ComponentSRNANDLatch()
{
    this->setName(std::string("sr_nand_latch"));
}

nts::Tristate nts::ComponentSRNANDLatch::compute(std::size_t pin)
{
    if (pins.at(1) != nullptr && pins.at(2) != nullptr && pins.at(3) != nullptr && pins.at(4) != nullptr) {
        if (*pins.at(1) == nts::Tristate::FALSE && *pins.at(2) == nts::Tristate::FALSE) {
            *pins.at(3) = nts::Tristate::UNDEFINED;
            *pins.at(4) = nts::Tristate::UNDEFINED;
        } else if (*pins.at(1) == nts::Tristate::TRUE && *pins.at(2) == nts::Tristate::FALSE) {
            local = nts::Tristate::FALSE;
            *pins.at(3) = local;
            *pins.at(4) = ~local;
        } else if (*pins.at(1) == nts::Tristate::FALSE && *pins.at(2) == nts::Tristate::TRUE) {
            local = nts::Tristate::TRUE;
            *pins.at(3) = local;
            *pins.at(4) = ~local;
        } else {
            *pins.at(3) = local;
            *pins.at(4) = ~local;
        }
    }
    return *pins.at(pin);
}

std::unique_ptr<nts::IComponent> nts::ComponentSRNANDLatch::clone(const std::string &value)
{
    auto component = std::make_unique<nts::ComponentSRNANDLatch>(*this);
    (void) value;
    component.get()->pins.resize(5);
    component.get()->local = nts::Tristate::FALSE;
    return component;
}
