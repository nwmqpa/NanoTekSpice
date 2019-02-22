/*
** EPITECH PROJECT, 2019
** Simulation.hpp
** File description:
** Simulation header
*/

#ifndef SIMULATION_HPP_
    #define SIMULATION_HPP_

#include "Parser.hpp"
#include "ComponentFactory.hpp"
#include <map>
#include <regex>

class Simulation {
    public:
        Simulation() = default;
        ~Simulation() = default;
        nts::IComponent *getComponent(const std::string &name);
        void setupChipsets();
        void setupLinks();
        void setup();
        void actionChoice(const std::string &line, std::smatch match);
        void run();
        void exit();
        void display();
        void simulate();
        void loop();
        void dump();
        void setInput(const std::string &name, const std::string &value);
        void getUserInput();
    private:
        std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _input;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _output;
        std::string _lastInput;
        Parser _parser;
        bool _isRunning;
};

#endif /* SIMULATION_HPP_ */
