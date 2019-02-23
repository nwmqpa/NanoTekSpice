/*
** EPITECH PROJECT, 2019
** Simulation.cpp
** File description:
** Simulation implementation
*/

#include "Simulation.hpp"
#include "Utils.hpp"
#include "AbstractComponent.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

Simulation::Simulation()
    : _components(std::map<std::string, std::unique_ptr<nts::IComponent>>())
    , _inputs(std::map<std::string, std::unique_ptr<nts::IComponent>>())
    , _outputs(std::map<std::string, std::unique_ptr<nts::IComponent>>())
    , _parser(Parser())
    , _isReady(false)
{}

nts::IComponent *Simulation::getComponent(const std::string &name)
{
    for (auto i = _components.begin(); i != _components.end(); i++) {
        auto cursor = i->first;
        if (cursor == name)
            return _components[cursor].get();
    }
    for (auto i = _inputs.begin(); i != _inputs.end(); i++) {
        auto cursor = i->first;
        if (cursor == name)
            return _inputs[cursor].get();
    }
    for (auto i = _outputs.begin(); i != _outputs.end(); i++) {
        auto cursor = i->first;
        if (cursor == name)
            return _outputs[cursor].get();
    }
    return nullptr;
}

void Simulation::setupChipsets()
{
    auto chipsets = _parser.getChipsets();

    for (auto [type, name, param] : chipsets) {
        if (!type.compare("input"))
            _inputs[name] = std::move(nts::ComponentFactory::getFactory()->createComponent(type, param));
        else if (!type.compare("output"))
            _outputs[name] = std::move(nts::ComponentFactory::getFactory()->createComponent(type, param));
        else
            _components[name] = std::move(nts::ComponentFactory::getFactory()->createComponent(type, param));
    }
}

void Simulation::setupLinks()
{
    auto links = _parser.getLinks();

    for (auto [c1, p1, c2, p2] : links) {
        getComponent(c1)->setLink(std::stoi(p1), *getComponent(c2), std::stoi(p2));
    }
}

void Simulation::setup(int ac, char *av[])
{
    std::regex reg("([a-zA-Z0-9_]+)=([01]?)");
    std::smatch match;
    std::string line;
    std::vector<std::string> tmp;

    if (ac < 2) {
        std::cerr << program_invocation_short_name << ": nts file not specified." << std::endl;
        return;
    }
    if (!_parser.parseFile(av[1]))
        return;
    setupChipsets();
    setupLinks();
    if ((ac != (2 + _parser.countComponent("input")))) {
        std::cerr << program_invocation_short_name << ": all inputs values must be specified (no more, no less)." << std::endl;
        return;
    }
    _isReady = true;
    for (int i = 2; i != ac; i++) {
        line.assign(av[i]);
        if (std::regex_match(line, match, reg) && !isValidArgument(tmp, match[1])) {
            _isReady = false;
            return;
        } else if (!std::string(match[2]).empty()) {
            setInput(match[1], match[2]);
            tmp.push_back(match[2]);
        } else {
            std::cerr << program_invocation_short_name << ": " << line << ": invalid option." << std::endl;
            _isReady = false;
            return;
        }
    }
}

void Simulation::actionChoice(const std::string &line, std::smatch match)
{
    if (!line.compare("dump"))
        dump();
    else if (!line.compare("exit"))
        exit();
    else if (!line.compare("simulate"))
        simulate();
    else if (!line.compare("loop"))
        loop();
    else if (!line.compare("display"))
        display();
    else
        setInput(match[1], match[2]);
}

void Simulation::run()
{
    std::regex reg("(?:([a-zA-Z0-9_]+)=([01]))|(dump|exit|simulate|loop|display)");
    std::smatch match;
    std::string line;

    if (!_isReady)
        return exit();
    nts::debug << "Starting simulation..." << std::endl;
    simulate();
    while (_isReady) {
        if ((line = getUserInput()).empty())
            return exit();
        if (std::regex_match(line, match, reg))
            actionChoice(match[0], match);
        else
            std::cerr << program_invocation_short_name << ": " << line << ": invalid option." << std::endl;
    }
}

void Simulation::exit()
{
    for (auto i = _inputs.begin(); i != _inputs.end();)
        i = _inputs.erase(i);
    for (auto i = _outputs.begin(); i != _outputs.end();)
        i = _outputs.erase(i);
    for (auto i = _components.begin(); i != _components.end();)
        i = _components.erase(i);
    _isReady = false;
}

void Simulation::display()
{
    for (auto i = _outputs.begin(); i != _outputs.end(); i++) {
        auto cursor = i->first;
        std::cout << cursor << "=" << static_cast<nts::AbstractComponent *>(_outputs[cursor].get())->getOutput() << std::endl;
    }
}

void Simulation::simulate()
{
    for (auto i = _components.begin(); i != _components.end(); i++) {
        auto cursor = i->first;
        _components[cursor]->compute();
    }
    display();
}

void Simulation::loop()
{}

void Simulation::dump()
{
    for (auto i = _components.begin(); i != _components.end(); i++) {
        auto cursor = i->first;
        _components[cursor]->dump();
    }
}

void Simulation::setInput(const std::string &name, const std::string &value)
{
    if (getComponent(name) == nullptr) {
        std::cerr << program_invocation_short_name << ": can\'t find \'" << name << "\'." << std::endl;
        return;
    }
    if (!value.compare("0"))
        static_cast<nts::AbstractComponent *>(getComponent(name))->setPinAt(1, nts::Tristate::FALSE);
    else
        static_cast<nts::AbstractComponent *>(getComponent(name))->setPinAt(1, nts::Tristate::TRUE);
}

std::string Simulation::getUserInput()
{
    std::string line;

    std::cout << "> ";
    std::getline(std::cin, line);
    return line;
}

bool Simulation::isValidArgument(std::vector<std::string> &list, const std::string &name)
{
    auto chipsets = _parser.getChipsets();
    bool inChips = false;

    for (std::string elem : list) {
        if (!name.compare(elem)) {
            std::cerr << program_invocation_short_name << ": \'" << name << "\' value is set multiple times." << std::endl;
            return false;
        }
    }
    for (auto [cType, cName, cParam] : chipsets) {
        if (!name.compare(cName)) {
            inChips = true;
            break;
        }
    }
    if (!inChips) {
        std::cerr << program_invocation_short_name << ": can\'t find \'" << name << "\'." << std::endl;
        return false;
    }
    return true;
}
