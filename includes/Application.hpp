/*
** EPITECH PROJECT, 2019
** Application.hpp
** File description:
** Application
*/

#ifndef _APP_HPP_
#   define _APP_HPP_

#   ifdef INSTALL_PATH
#       define STR_EXPAND2(tok) #tok
#      define STR_EXPAND(tok) STR_EXPAND2(tok)
#       define INSTALL_PATH_STR STR_EXPAND(INSTALL_PATH)
#   else
#       define INSTALL_PATH_STR "."
#   endif

#   include <vector>
#   include <iostream>
#   include "ComponentFactory.hpp"
#   include "PluginLoader.hpp"
#   include "Simulation.hpp"

namespace nts {
    class Application {
        public:
            Application();
            ~Application();

            void setup(int ac, char *av[]) noexcept;
            void run();
        private:
            nts::ComponentFactory factory;
            nwmqpa::PluginLoader pluginLoader;
            Simulation simulation;
            bool isRunning;
    };
}

#endif /* _APP_HPP_ */
