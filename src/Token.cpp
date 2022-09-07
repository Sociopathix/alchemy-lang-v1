#include "../include/Token.hpp"

Token::Token(TokenType type, string value)
{
    this->type = type;
    this->value = value;
}

string Token::get_value()
{
    return value;
}

string Token::get_type()
{
    string type_names[] = 
    {
        // Single-character tokens.
        "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_BRACE", "RIGHT_BRACE",
        "COMMA", "DOT", "MINUS", "PLUS", "SEMICOLON", "SLASH", "ASTERICK",

        // One or two character tokens.
        "NOT", "NOT_EQUAL",
        "EQUAL", "EQUAL_EQUAL",
        "GREATER", "GREATER_EQUAL", "GREATER_GREATER",
        "LESS", "LESS_EQUAL", "LESS_LESS",

        // Literals.
        "IDENTIFIER", "STRING", "NUMBER",

        // Keywords. Change NONE to NIL??
        "KEYWORD", // Might just simplify it down to KEYWORD...
        "AND", "CLASS", "IF", "ELSE", "FALSE", "FUNC", "FOR", "NONE", "OR",
        "PRINT", "RETURN", "SUPER", "THIS", "TRUE", "VAR", "WHILE",

        // Other.
        "END_LINE", "END_FILE"
    };

    string type_name = type_names[type];
    return type_name;
}