/*
** EPITECH PROJECT, 2019
** Parser.cpp
** File description:
** Parser implementation
*/

#include "Parser.hpp"
#include "ComponentFactory.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <regex>

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

bool Parser::isValidLine(const std::string &line)
{
    std::regex chipReg("([a-zA-Z0-9_]+)[ \t]+([a-zA-Z0-9_]+)\\(?([\\w.]*)\\)?");
    std::regex linkReg("([a-zA-Z0-9_]+):([0-9]+)[ \t]+([a-zA-Z0-9_]+):([0-9]+)");
    std::smatch match;

    if (!line.compare(".chipsets:")) {
        if (_isChips)
            std::cerr << program_invocation_short_name << ": multiple \'.chipsets:\' definition." << std::endl;
        return _isChips ? (_isChips = false) : (_isChips = true);
    }
    if (!line.compare(".links:")) {
        if (_isLinks)
            std::cerr << program_invocation_short_name << ": multiple \'.links:\' definition." << std::endl;
        return _isLinks ? (_isLinks = false) : (_isLinks = true);
    }
    if ((std::regex_match(line, match, chipReg)) || (std::regex_search(line, match, linkReg))) {
        if (!_isLinks && _isChips) {
            if (!isValidType(match[1])) {
                std::cerr << program_invocation_short_name << ": \'" << match[1] << "\' component type is unknown." << std::endl;
                return false;
            } else if (isAlreadyAdded(match[2])) {
                std::cerr << program_invocation_short_name << ": multiple \'" << match[2] << "\' definition." << std::endl;
                return false;
            } else
                _chipsets.push_back(std::make_tuple(match[1], match[2], match[3]));
        } else if (_isLinks)
            _links.push_back(std::make_tuple(match[1], match[2], match[3], match[4]));
        return true;
    } else
        return false;
}

bool Parser::isValidFile()
{
    for (std::string line : _fileContent)
        if (!isValidLine(line))
            return false;
    // is component registered
    // is output linked
    if (!_isChips || !_isLinks) {
        if (!_isChips)
            std::cerr << program_invocation_short_name << ": no \'.chipsets:\' section found." << std::endl;
        if (!_isLinks)
            std::cerr << program_invocation_short_name << ": no \'.links:\' section found." << std::endl;
        return false;
    }
    return true;
}

bool Parser::isValidFilePath(const std::string &filePath)
{
    if (!std::filesystem::exists(filePath)) {
        std::cerr << program_invocation_short_name << ": \'" << filePath << "\' doesn't exist." << std::endl;
        return false;
    }
    if (std::filesystem::is_directory(filePath)) {
        std::cerr << program_invocation_short_name << ": \'" << filePath << "\' is a directory." << std::endl;
        return false;
    }
    return true;
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

bool Parser::parseFile(const std::string &filePath)
{
    if (!isValidFilePath(filePath))
        return false;
    _filePath.assign(filePath);
    _fileContent.clear();
    _isChips = false;
    _isLinks = false;
    getFileContent();
    if (!isValidFile())
        return false;
    return true;
}
