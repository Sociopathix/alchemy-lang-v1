#ifndef ALCHEMY_HPP
#define ALCHEMY_HPP

#include "Lexer.hpp"
#include "Token.hpp"

#include <iostream>
using namespace std;

class Alchemy
{
    public:

        // Class Variables.
        string code;

        // Class Constructor.
        Alchemy(string code);
        
        // Class Functions.
        void run();
};

#endif