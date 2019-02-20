/*
** EPITECH PROJECT, 2019
** Simulation.hpp
** File description:
** Simulation header
*/

#ifndef SIMULATION_HPP_
    #define SIMULATION_HPP_

#include "Parser.hpp"

class Simulation {
    public:
        Simulation() = default;
        ~Simulation() = default;
        void setup();
        void run();
        void exit();
        void display();
        void simulate();
        void loop();
        void dump();
        void setInput();
        std::string getLastInput() const { return _lastInput; };
        void getUserInput();
        Parser parser;
    private:
        std::string _lastInput;
};

#endif /* SIMULATION_HPP_ */
