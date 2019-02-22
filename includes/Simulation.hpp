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

class Simulation {
    public:
        Simulation() = default;
        ~Simulation() = default;
        nts::IComponent *getComponent(const std::string &name);
        void setupChipsets();
        void setupLinks();
        void setup();
        void run();
        void exit();
        void display();
        void simulate();
        void loop();
        void dump();
        void setInput(const std::string &variable, const std::string &value);
        std::string getLastInput() const { return _lastInput; };
        void getUserInput();
    private:
        std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _input;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _output;
        std::string _lastInput;
        Parser _parser;
};

#endif /* SIMULATION_HPP_ */
