/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** main
*/

#include "Application.hpp"
#include "Simulation.hpp"

int main(int __attribute__((unused)) ac, char *av[])
{
    nts::Application app;
    app.setup();
    app.run();

    //app.simulation.getUserInput();
    //app.simulation.parser.parseFile(app.simulation.getLastInput());
    //app.simulation.parser.printContent();
}
