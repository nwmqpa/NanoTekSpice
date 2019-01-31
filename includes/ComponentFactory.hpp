/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
    #define COMPONENTFACTORY_HPP_

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "IComponent.hpp"

namespace nts {
    class ComponentFactory {
        public:
            ComponentFactory();
            ~ComponentFactory() = default;

            bool registerComponent(nts::IComponent *component, const std::string &name);
            std::unique_ptr<nts::IComponent> createComponent(const std::string &name, const std::string &value) const;
            std::vector<std::string> getNames() const;
            static nts::ComponentFactory *getFactory();

        private:
            static nts::ComponentFactory *singleton;
            std::map<std::string, nts::IComponent *> instances;
    };
}

#endif /* !COMPONENTFACTORY_HPP_ */
