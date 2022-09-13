#ifndef PARSER_HPP
#define PARSER_HPP

#include "Token.hpp"
#include "TokenType.hpp"

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Parser
{
    public:

        // Class Variables.
        vector<Token> tokens;

        // Class Constructor.
        Parser(vector<Token> tokens);
        
        // Class Functions.
        bool parse();
};

#endif