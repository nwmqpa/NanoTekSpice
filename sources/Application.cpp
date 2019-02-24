/*
** EPITECH PROJECT, 2019
** Application.cpp
** File description:
** Application
*/

#include "Exception.hpp"
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "Application.hpp"
#include "Utils.hpp"

nts::Application::Application()
    : factory(nts::ComponentFactory())
    , pluginLoader(nwmqpa::PluginLoader())
    , simulation(Simulation())
    , isRunning(false)
{}

nts::Application::~Application()
{
    pluginLoader.unloadPlugins();
}

void nts::Application::setup(int ac, char *av[]) noexcept
{
    chdir(INSTALL_PATH_STR);
    nts::debug << "Path is: " << INSTALL_PATH_STR << std::endl;
    pluginLoader.loadPlugins<nts::ComponentFactory>(&factory, std::string("./components"));
    try {
        simulation.setup(ac, av);
    } catch (nts::ArgsError const &error) {
        std::cerr << program_invocation_short_name << ": " << error.what() << std::endl;
        exit(84);
    }
}

void nts::Application::run()
{
    nts::debug << "Launching the application." << std::endl;
    for (const std::string &name : factory.getNames()) {
        nts::debug << name << std::endl;
    }
    simulation.run();
}
