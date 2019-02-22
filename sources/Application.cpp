/*
** EPITECH PROJECT, 2019
** Application.cpp
** File description:
** Application
*/

#include <exception>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "Application.hpp"
#include "Utils.hpp"

nts::Application::Application()
    : simulation(Simulation())
    , factory(nts::ComponentFactory())
    , pluginLoader(nwmqpa::PluginLoader())
    , isRunning(false)
{}

nts::Application::~Application()
{
    pluginLoader.unloadPlugins();
}

void nts::Application::setup() noexcept
{
    chdir(INSTALL_PATH_STR);
    nts::debug << "Path is: " << INSTALL_PATH_STR << std::endl;
    pluginLoader.loadPlugins<nts::ComponentFactory>(&factory, std::string("./components"));
}

void nts::Application::run()
{
    nts::debug << "Launching the application." << std::endl;
    for (const std::string &name : factory.getNames()) {
        nts::debug << name << std::endl;
    }
    simulation.setup();
    simulation.run();
}
