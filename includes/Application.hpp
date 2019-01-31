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

namespace nts {
    class Application {
        public:
            Application();
            ~Application() = default;

            void setup() noexcept;
            void run();

        private:
            nts::ComponentFactory factory;
            nwmqpa::PluginLoader pluginLoader;
            bool isRunning;
    };
}

#endif /* _APP_HPP_ */
