#ifndef LEXER_HPP
#define LEXER_HPP

#include "Token.hpp"

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Lexer
{
    public:

        // Class Variables.
        string code;
        vector<Token> tokens;

        // Class Constructor.
        Lexer(string code);
        
        // Class Functions.
        vector<Token> tokenize();
        void print_tokens(); 
};

#endif