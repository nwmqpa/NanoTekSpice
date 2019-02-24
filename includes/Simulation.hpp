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
        Simulation();
        ~Simulation() = default;
        nts::IComponent *getComponent(const std::string &name);
        void setupChipsets();
        void setupLinks();
        void setup(int ac, char *av[]);
        void actionChoice(const std::string &line, std::smatch match);
        void run();
        void exit();
        void display();
        void simulate();
        void loop();
        void dump();
        void setInput(const std::string &name, const std::string &value);
        std::string getUserInput();
    private:
        void isValidArgument(std::vector<std::string> &list, const std::string &name);
        std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _inputs;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _outputs;
        Parser _parser;
        bool _isReady;
};

#endif /* SIMULATION_HPP_ */
