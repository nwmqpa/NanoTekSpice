/*
** EPITECH PROJECT, 2019
** cpp_rush3_2018
** File description:
** ModuleFactory
*/

#include <iostream>
#include "ComponentFactory.hpp"
#include "Utils.hpp"

nts::ComponentFactory *nts::ComponentFactory::singleton = nullptr;

nts::ComponentFactory::ComponentFactory()
: pins(),
  instances()
{
    if (singleton == nullptr)
        singleton = this;
}

nts::ComponentFactory::~ComponentFactory()
{
    for (; pins.size() != 0; ) {
        delete pins.back();
        pins.pop_back();
    }
}

bool nts::ComponentFactory::registerComponent(nts::IComponent *component, const std::string &name)
{
    if (name.size() == 0) {
        std::cerr << "Cannot register component: No name given" << std::endl;
        return false;
    }
    if (component == nullptr) {
        std::cerr << "Cannot register component " << name << ": pointer is null" << std::endl;
        return false;
    }
    for (auto &temp : this->instances) {
        if (temp.first.compare(name) == 0) {
            std::cerr << "Cannot register component: " << name << ", name already registered" << std::endl;
            return false;
        }
    }
    this->instances[name] = component;
    nts::debug << "Component " << name << " registered." << std::endl;
    return true;
}

void nts::ComponentFactory::registerPin(nts::Tristate *pin)
{
    pins.push_back(pin);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &name, const std::string &value) const
{
    try {
        return this->instances.at(name)->clone(value);
    } catch (const std::out_of_range &e) {
        throw std::runtime_error(std::string("No such component: ") + name);
    }
}

std::vector<std::string> nts::ComponentFactory::getNames() const
{
    std::vector<std::string> names;
    for (auto &temp : this->instances) {
        names.push_back(temp.first);
    }
    return (names);
}

nts::ComponentFactory *nts::ComponentFactory::getFactory()
{
    return ComponentFactory::singleton;
}
