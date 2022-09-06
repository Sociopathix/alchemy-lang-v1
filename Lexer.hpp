#ifndef LEXER_HPP
#define LEXER_HPP

#include "Token.hpp"

#include <iostream>
using namespace std;

class Lexer
{
    public:

        // Class Variables.
        string code;

        // Class Constructor.
        Lexer();
        
        // Class Functions.
        list<Token> tokenize(string code);
        
};

#endif