#ifndef SYNTAXTREE_HPP
#define SYNTAXTREE_HPP

#include "SyntaxTreeType.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class SyntaxTree
{
    public:
        // Class Variables.
        SyntaxTreeType type;

        // Class Constructors.
        SyntaxTree(SyntaxTreeType type);

        // Class Functions.
        SyntaxTreeType get_type();
        string get_type_name();
};

#endif