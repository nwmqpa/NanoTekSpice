/*
** EPITECH PROJECT, 2019
** Parser.cpp
** File description:
** Parser implementation
*/

#include "Exception.hpp"
#include "Parser.hpp"
#include "ComponentFactory.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <regex>

bool Parser::isLinked(const std::string &name)
{
    for (auto [c1, p1, c2, p2] : _links)
        if (!name.compare(c1) || !name.compare(c2))
            return true;
    return false;
}

bool Parser::isValidType(const std::string &typeName)
{
    auto types = nts::ComponentFactory::getFactory()->getNames();

    for (auto type : types)
        if (!typeName.compare(type))
            return true;
    return false;
}

bool Parser::isAlreadyAdded(const std::string &name)
{
    for (auto line : _chipsets)
        if (!name.compare(std::get<1>(line)))
            return true;
    return false;
}

void Parser::isValidLine(const std::string &line)
{
    std::regex chipReg("([a-zA-Z0-9_]+)[ \t]+([a-zA-Z0-9_]+)\\(?([\\w.]*)\\)?");
    std::regex linkReg("([a-zA-Z0-9_]+):([0-9]+)[ \t]+([a-zA-Z0-9_]+):([0-9]+)");
    std::smatch match;

    if (!line.compare(".chipsets:")) {
        if (_isChips)
            throw nts::SyntaxError("multiple \'.chipsets:\' definition.");
        _isChips ? (_isChips = false) : (_isChips = true);
    }
    if (!line.compare(".links:")) {
        if (_isLinks)
            throw nts::SyntaxError("multiple \'.links:\' definition.");
        _isLinks ? (_isLinks = false) : (_isLinks = true);
    }
    if ((std::regex_match(line, match, chipReg)) || (std::regex_search(line, match, linkReg))) {
        if (!_isLinks && _isChips) {
            if (!isValidType(match[1]))
                throw nts::SyntaxError("\'" + std::string(match[1]) + "\' component type is unknown.");
            else if (isAlreadyAdded(match[2]))
                throw nts::SyntaxError("multiple \'" + std::string(match[2]) + "\' definition.");
            else
                _chipsets.push_back(std::make_tuple(match[1], match[2], match[3]));
        } else if (_isLinks)
            _links.push_back(std::make_tuple(match[1], match[2], match[3], match[4]));
    }
}

void Parser::isValidFile()
{
    for (std::string line : _fileContent) {
        try {
            isValidLine(line);
        } catch (nts::SyntaxError const &error) {
            std::cerr << program_invocation_short_name << ": " << error.what() << std::endl;
            exit(84);
        }
    }
    if (!_isChips || !_isLinks) {
        if (!_isChips)
            throw nts::SyntaxError("no \'.chipsets:\' section found.");
        if (!_isLinks)
            throw nts::SyntaxError("no \'.links:\' section found.");
    }
    for (auto [type, name, param] : _chipsets)
        if (!type.compare("output") && !isLinked(name))
            throw nts::SyntaxError("Output \'" + name + "\' is not linked to anything.");
}

void Parser::isValidFilePath(const std::string &filePath)
{
    if (!std::filesystem::exists(filePath))
        throw nts::FileError("\'" + filePath + "\' doesn't exist.");
    if (std::filesystem::is_directory(filePath))
        throw nts::FileError("\'" + filePath + "\' is a directory.");
}

bool Parser::isUselessLine(const std::string &line)
{
    if (line.empty())
        return true;
    return false;
}

void Parser::cleanContent()
{
    std::regex reg("( |\t)*#.*");
    std::smatch match;

    for (size_t i = 0; i != _fileContent.size(); i++) {
        if (std::regex_search(_fileContent[i], match, reg))
            _fileContent[i].resize(match.position());
        if (isUselessLine(_fileContent[i]))
            _fileContent.erase(_fileContent.begin() + i--);
    }
}

void Parser::getFileContent()
{
    std::ifstream fileStream(_filePath);
    std::string line;

    while (std::getline(fileStream, line))
        _fileContent.push_back(line);
    cleanContent();
}

void Parser::parseFile(const std::string &filePath)
{
    try {
        isValidFilePath(filePath);
    } catch (nts::FileError const &error) {
        std::cerr << program_invocation_short_name << ": " << error.what() << std::endl;
        exit(84);
    }
    _filePath.assign(filePath);
    _fileContent.clear();
    _isChips = false;
    _isLinks = false;
    getFileContent();
    try {
        isValidFile();
    } catch (nts::SyntaxError const &error) {
        std::cerr << program_invocation_short_name << ": " << error.what() << std::endl;
        exit(84);
    }
}

int Parser::countComponent(const std::string &name)
{
    int count = 0;

    if (!name.compare("ALL"))
        return _chipsets.size();
    for (auto comp : _chipsets)
        if (!name.compare(std::get<0>(comp)))
            count++;
    return count;
}
