/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** PluginLoader
*/

#include "PluginLoader.hpp"

nwmqpa::PluginLoader::PluginLoader() : _plugins(std::vector<void *>())
{
}

void nwmqpa::PluginLoader::unloadPlugins() noexcept
{
    if (this->_plugins.size() <= 0)
        return;
#ifdef DEBUG
    std::cout << "Unloading " << this->_plugins.size() << " plugins..." << std::endl;
#endif
    for (auto &handle : this->_plugins) {
        dlclose(handle);
    }
}
