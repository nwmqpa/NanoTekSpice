/*
** EPITECH PROJECT, 2019
** Parser.cpp
** File description:
** Parser implementation
*/

#include "Parser.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <regex>

bool Parser::isValidLine(const std::string &line)
{
    std::regex chipReg("([a-zA-Z0-9_]+)[ \t]+([a-zA-Z0-9_]+)\\(?([\\w.]*)\\)?");
    std::regex linkReg("([a-zA-Z0-9_]+):([0-9]+)[ \t]+([a-zA-Z0-9_]+):([0-9]+)");
    std::smatch match;

    if (!line.compare(".chipsets:")) {
        if (_isChips)
            std::cout << program_invocation_short_name << ": multiple \'.chipsets:\' definition." << std::endl;
        return _isChips ? (_isChips = false) : (_isChips = true);
    }
    if (!line.compare(".links:")) {
        if (_isLinks)
            std::cout << program_invocation_short_name << ": multiple \'.links:\' definition." << std::endl;
        return _isLinks ? (_isLinks = false) : (_isLinks = true);
    }
    if ((std::regex_match(line, match, chipReg)) || (std::regex_search(line, match, linkReg)))
        return true;
    else
        return false;
}

bool Parser::isValidFile()
{
    for (std::string line : _fileContent)
        if (!isValidLine(line))
            return false;
    // is component registered
    // component with same name
    // is output linked
    return true;
}

bool Parser::isValidFilePath(const std::string &filePath)
{
    if (!std::filesystem::exists(filePath)) {
        std::cout << program_invocation_short_name << ": \'" << filePath << "\' doesn't exist." << std::endl;
        return false;
    }
    if (std::filesystem::is_directory(filePath)) {
        std::cout << program_invocation_short_name << ": \'" << filePath << "\' is a directory." << std::endl;
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
        if (std::regex_search(_fileContent[i], match, reg)) {
            _fileContent[i].resize(match.position());
        }
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
    if (!isValidFilePath(filePath))
        return;
    _filePath.assign(filePath);
    _fileContent.clear();
    _isChips = false;
    _isLinks = false;
    getFileContent();
    if (!isValidFile())
        return;
}

void Parser::printContent()
{
    for (std::string line : _fileContent)
        std::cout << "[" << line << "]" << std::endl;
}
