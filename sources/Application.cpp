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
    : factory(nts::ComponentFactory())
    , pluginLoader(nwmqpa::PluginLoader())
    , isRunning(false)
{}

void nts::Application::setup() noexcept
{
    chdir(INSTALL_PATH_STR);
    nts::debug << "Path is: " << INSTALL_PATH_STR << std::endl;
    pluginLoader.loadPlugins<nts::ComponentFactory>(&factory, std::string("./components"));
}

void nts::Application::run()
{
    nts::debug << "Launching the application." << std::endl;
    pluginLoader.unloadPlugins();
}
