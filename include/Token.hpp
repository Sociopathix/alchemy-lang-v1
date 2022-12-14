#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "TokenType.hpp"
#include <list>
#include <iostream>
using namespace std;

class Token
{
    public:

        // Class Variables.
        TokenType type;
        string value;

        // Class Constructor.
        Token();
        Token(TokenType type, string value);    

        // Class Functions.
        void print_self();
        string get_type_name();
        string get_value();
        TokenType get_type();
};

#endif