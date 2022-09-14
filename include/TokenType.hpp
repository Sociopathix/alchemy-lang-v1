#ifndef TOKENTYPE_HPP
#define TOKENTYPE_HPP

enum TokenType 
{
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, ASTERICK,

    // One or two character tokens.
    EXCL, EXCL_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL, RIGHT_COMMENT,
    LESS, LESS_EQUAL, LEFT_COMMENT,

    // Literals.
    IDENTIFIER, STRING, NUMBER,

    // Keywords.
    AND, CLASS, IF, ELSE, FALSE, FUNC, FOR, NONE, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE, NOT,

    // Other.
    END_LINE, END_FILE 
};

#endif