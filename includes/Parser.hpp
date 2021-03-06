/*
** EPITECH PROJECT, 2019
** Parser.hpp
** File description:
** Parser header
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

#include <string>
#include <vector>
#include <tuple>
#include <map>

class Parser {
    public:
        Parser() = default;
        ~Parser() = default;
        void parseFile(const std::string &filePath);
        int countComponent(const std::string &name = "ALL");
        std::vector<std::tuple<std::string, std::string, std::string>> getChipsets() const { return _chipsets; };
        std::vector<std::tuple<std::string, std::string, std::string, std::string>> getLinks() const { return _links; };
    private:
        bool isLinked(const std::string &name);
        bool isValidType(const std::string &typeName);
        bool isAlreadyAdded(const std::string &name);
        void isValidLine(const std::string &line);
        void isValidFile();
        void isValidFilePath(const std::string &filePath);
        bool isUselessLine(const std::string &line);
        void cleanContent();
        void getFileContent();
        std::string _filePath;
        std::vector<std::string> _fileContent;
        std::vector<std::tuple<std::string, std::string, std::string>> _chipsets;
        std::vector<std::tuple<std::string, std::string, std::string, std::string>> _links;
        bool _isChips;
        bool _isLinks;
};

#endif /* PARSER_HPP_ */
