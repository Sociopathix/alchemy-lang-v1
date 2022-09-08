#ifndef ALCHEMY_HPP
#define ALCHEMY_HPP

#include "Lexer.hpp"
#include "Token.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Alchemy
{
    public:

        // Class Variables.
        string file_path;
        string code;

        // Class Constructors.
        Alchemy();
        Alchemy(string file_path);
        
        // Class Functions.
        void run();
        string read_file(string file_path);
};

#endif