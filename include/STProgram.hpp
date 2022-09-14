#ifndef STPROGRAM_HPP
#define STPROGRAM_HPP

#include "SyntaxTree.hpp"
#include "SyntaxTreeType.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class STProgram : public SyntaxTree
{
    public:

        // Class Variables.


        // Class Constructors.
        STProgram(SyntaxTree body);

        // Class Functions.
};

#endif