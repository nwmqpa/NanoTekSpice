/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** 4071Component
*/

#include "Utils.hpp"
#include "ComponentTerminalOutput.hpp"

nts::ComponentTerminalOutput::ComponentTerminalOutput()
{
    this->setName(std::string("terminal_output"));
}

nts::Tristate nts::ComponentTerminalOutput::compute(std::size_t pin)
{
    char c = 0;
    for (std::size_t i = 1; i < 9; i++) {
        if (pins.at(i) != nullptr) {
            c += (*pins.at(i) == nts::Tristate::TRUE ? 1 : 0) << (i - 1);
        }
    }
    if (pins.at(9) != nullptr && *pins.at(9) == nts::Tristate::TRUE)
        std::cout << c << std::flush;
    return *pins.at(pin);
}

std::unique_ptr<nts::IComponent> nts::ComponentTerminalOutput::clone(const std::string &value)
{
    auto component = std::make_unique<nts::ComponentTerminalOutput>(*this);
    (void) value;
    component.get()->pins.resize(10);
    return component;
}
