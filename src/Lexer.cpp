#include "../include/Lexer.hpp"

Lexer::Lexer(string code)
{
    this->code = code;
}

vector<Token> Lexer::tokenize()
{
    string keywords[] = 
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

        if (current_character == ' ' or current_character == '\n')
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

        // Keywords and variables.
        else if (variable_characters.find(current_character) != string::npos) 
        {
            string result = "";
            
            // while the next char is a valid variable/keyword charater
            while (variable_characters.find(code[position]) != string::npos and position < LENGTH) 
            {
                // adding the char to the string
                result += code[position];
                position++;
            }

            // if the keyword is not a built in keyword
            int n = (sizeof(keywords) / sizeof(*keywords));
            if(find(keywords, keywords + n, result) == keywords + n)
            {
                cout << "Lexer Error: Unexpected token " << result << " (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
                break;
            }

            TokenType type = TokenType::KEYWORD;
            Token new_token = Token(type, result);
            tokens.push_back(new_token);
        }

        else if(current_character == ';')
        {
            position++;

            // adding the string to the tokens
            TokenType type = TokenType::END_LINE;
            Token new_token = Token(type, ";");
            tokens.push_back(new_token);
        }

        // we have a invalid character in our code
        else 
        { 
          cout << "Lexer Error: Unexpected character " << code[position] << " (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
          break;
        }
    }

   // adding the string to the tokens
    TokenType type = TokenType::END_FILE;
    Token new_token = Token(type, "EOF");
    tokens.push_back(new_token); 

    return tokens;
}

void Lexer::print_tokens()
{
    int counter = 0;
    cout << "TOKENS:" << endl << "{" << endl;
    for (Token token : tokens) 
    {
        cout << "\tTYPE: " << token.get_type() << "\t VALUE: " << token.get_value();
        if (counter < tokens.size() - 1)
        {
            cout << " ," << endl;
        }

        counter++;
    }

    cout << endl; 
    cout << "}" << endl;
}