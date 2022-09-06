#include "Lexer.hpp"

#include <algorithm>
#include <iostream>
using namespace std;

Lexer::Lexer()
{
    return;
}

list<Token> Lexer::tokenize(string code)
{
    cout << "Lexer Output: " << code << endl;

    list<Token> tokens;

    const list<string> keywords = 
    {
        "and", "class", "if", "else", "elif", 
        "else", "true", "false", "func", "for", 
        "while", "null", "or", "print", "return", 
        "this", "super", "var"
    };
    const string variable_characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_1234567890";

    const int LENGTH = code.length();
    int line = 0;
    int position = 0;

    while (position < LENGTH)
    {
        char current_character = code[position];

        if (current_character == ' ' || current_character == '\n')
        {
            position++;
            continue;
        }

        // start of a string!!
        else if (current_character == '"')
        {
            string result = "";
            position++;

            // while next char is not " or \n and we are not at the end of the code
            while (code[position] != '"' && code[position] != '\n' && position < LENGTH) 
            {
                // adding the char to the string
                result += code[position];
                position++;
            }
            
            // if the loop ended because of the end of the code and we didn't find the closing quotation mark.
            if (code[position] != '"') 
            {
                cout << "Lexer Error: Unterminated string! (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
                break;
            }

            position++;

            // adding the string to the tokens
            TokenType type = TokenType::STRING;
            Token new_token = Token(type, result);
            tokens.push_back(new_token);
        }

        else if (variable_characters.find(current_character) != string::npos) 
        {
            string result = to_string(current_character);
            
            // while the next char is a valid variable/keyword charater
            while (variable_characters.find(code[position]) != string::npos && position < LENGTH) 
            {
                // adding the char to the string
                result += code[position];
                position++;
            }

            // if the keyword is not a built in keyword
            if (find(keywords.begin(), keywords.end(), result) == keywords.end())
            {
                cout << "Lexer Error: Unexpected token " << result << " (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
                break;
            }

            TokenType type = TokenType::KEYWORD;
            Token new_token = Token(type, result);
            tokens.push_back(new_token);
        }

        // we have a invalid character in our code
        else 
        { 
          cout << "Lexer Error: Unexpected character " << code[position] << " (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
          break;
        }
    }

    return tokens;
}