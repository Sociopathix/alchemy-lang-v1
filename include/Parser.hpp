#ifndef PARSER_HPP
#define PARSER_HPP

#include "Token.hpp"
#include "TokenType.hpp"
#include "SyntaxTree.hpp"
#include "SyntaxTreeType.hpp"

#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Parser
{
    public:
        // Class Variables.
        vector<Token> tokens;
        vector<SyntaxTree> syntax_tree;
        Token current_token;
        int position;

        // Class Constructor.
        Parser(vector<Token> tokens);

        // Class Functions.
        vector<SyntaxTree> parse();
        SyntaxTree parse_expression();
        void increment_next();
        void print_syntax_tree();
};

#endif