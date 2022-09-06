#include "Token.hpp"

Token::Token(TokenType type, string value)
{
    this->type = type;
    this->value = value;
}