/*
** EPITECH PROJECT, 2019
** Exception.cpp
** File description:
** Exception implementation
*/

#include "Exception.hpp"

nts::NTSError::NTSError(const std::string &message) : _message(message)
{}

nts::ArgsError::ArgsError(const std::string &message) : NTSError(message)
{}

nts::FileError::FileError(const std::string &message) : ArgsError(message)
{}

nts::SyntaxError::SyntaxError(const std::string &message) : ArgsError(message)
{}
