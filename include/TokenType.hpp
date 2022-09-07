#ifndef TOKENTYPE_HPP
#define TOKENTYPE_HPP

#include <iostream>
using namespace std;

enum TokenType 
{
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, ASTERICK,

    // One or two character tokens.
    NOT, NOT_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL, GREATER_GREATER,
    LESS, LESS_EQUAL, LESS_LESS,

    // Literals.
    IDENTIFIER, STRING, NUMBER,

    // Keywords. Change NONE to NIL??
    KEYWORD, // Might just simplify it down to KEYWORD...
    AND, CLASS, IF, ELSE, FALSE, FUN, FOR, NONE, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    // Other.
    END_LINE, END_FILE 
};

#endif