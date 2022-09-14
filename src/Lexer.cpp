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
    const string variable_characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";

    const int LENGTH = code.length();
    int line = 0;
    int position = 0;

    while (position < LENGTH)
    {
        char current_character = code[position];

        // start of a string!!
        if (current_character == '"')
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
                cout << "<Lexer Error> Unterminated string! (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
                exit(0);
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
            while (variable_characters.find(code[position]) != string::npos && position < LENGTH) 
            {
                // adding the char to the string
                result += code[position];
                position++;
            }

            // if the keyword is not a built in keyword
            int n = (sizeof(keywords) / sizeof(*keywords));
            if(find(keywords, keywords + n, result) == keywords + n)
            {
                cout << "<Lexer Error> Unexpected token " << result << " (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
                exit(0);
            }

            position++;

            if(result == "print")
            {            
                TokenType type = TokenType::PRINT;
                Token new_token = Token(type, result);
                tokens.push_back(new_token);
            }

            else
            {
                cout << "<Lexer Error> Unexpected token " << result << " (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
                exit(0);
            }
        }

        else if(current_character == '(')
        {
            position++;

            // adding the string to the tokens
            TokenType type = TokenType::LEFT_PAREN;
            Token new_token = Token(type, "(");
            tokens.push_back(new_token);
        }

        else if(current_character == ')')
        {
            position++;

            // adding the string to the tokens
            TokenType type = TokenType::RIGHT_PAREN;
            Token new_token = Token(type, ")");
            tokens.push_back(new_token);
        }

        else if(current_character == '[')
        {
            position++;

            // adding the string to the tokens
            TokenType type = TokenType::LEFT_BRACKET;
            Token new_token = Token(type, "[");
            tokens.push_back(new_token);
        }

        else if(current_character == ']')
        {
            position++;

            // adding the string to the tokens
            TokenType type = TokenType::RIGHT_BRACKET;
            Token new_token = Token(type, "]");
            tokens.push_back(new_token);
        }

        else if(current_character == '{')
        {
            position++;

            // adding the string to the tokens
            TokenType type = TokenType::LEFT_BRACE;
            Token new_token = Token(type, "{");
            tokens.push_back(new_token);
        }

        else if(current_character == '}')
        {
            position++;

            // adding the string to the tokens
            TokenType type = TokenType::RIGHT_BRACE;
            Token new_token = Token(type, "}");
            tokens.push_back(new_token);
        }

        else if(current_character == ',')
        {
            position++;

            // adding the string to the tokens
            TokenType type = TokenType::COMMA;
            Token new_token = Token(type, ",");
            tokens.push_back(new_token);
        }

        else if(current_character == '.')
        {
            position++;

            // adding the string to the tokens
            TokenType type = TokenType::DOT;
            Token new_token = Token(type, ".");
            tokens.push_back(new_token);
        }

        else if(current_character == '-')
        {
            position++;

            // adding the string to the tokens
            TokenType type = TokenType::MINUS;
            Token new_token = Token(type, "-");
            tokens.push_back(new_token);
        }

        else if(current_character == '+')
        {
            position++;

            // adding the string to the tokens
            TokenType type = TokenType::PLUS;
            Token new_token = Token(type, "+");
            tokens.push_back(new_token);
        }

        else if(current_character == ';')
        {
            position++;

            // adding the string to the tokens
            TokenType type = TokenType::SEMICOLON;
            Token new_token = Token(type, ";");
            tokens.push_back(new_token);
        }

        else if(current_character == '/')
        {
            position++;

            // adding the string to the tokens
            TokenType type = TokenType::SLASH;
            Token new_token = Token(type, "/");
            tokens.push_back(new_token);
        }

        else if(current_character == '*')
        {
            position++;

            // adding the string to the tokens
            TokenType type = TokenType::ASTERICK;
            Token new_token = Token(type, "*");
            tokens.push_back(new_token);
        }

        else if(current_character == '!')
        {
            position++;
            current_character = code[position];
            
            if(current_character == '=')
            {
                position++;

                // adding the string to the tokens
                TokenType type = TokenType::EXCL_EQUAL;
                Token new_token = Token(type, "!=");
                tokens.push_back(new_token);
            }

            else
            {
                position++;
                
                // adding the string to the tokens
                TokenType type = TokenType::EXCL;
                Token new_token = Token(type, "!");
                tokens.push_back(new_token);
            }
        }

        else if(current_character == '=')
        {
            position++;
            current_character = code[position];
            
            if(current_character == '=')
            {
                position++;

                // adding the string to the tokens
                TokenType type = TokenType::EQUAL_EQUAL;
                Token new_token = Token(type, "==");
                tokens.push_back(new_token);
            }

            else
            {
                position++;
                
                // adding the string to the tokens
                TokenType type = TokenType::EQUAL;
                Token new_token = Token(type, "=");
                tokens.push_back(new_token);
            }
        }

        else if(current_character == '>')
        {
            position++;
            current_character = code[position];
            
            if(current_character == '=')
            {
                position++;

                // adding the string to the tokens
                TokenType type = TokenType::GREATER_EQUAL;
                Token new_token = Token(type, ">=");
                tokens.push_back(new_token);
            }
            
            else if(current_character == '>')
            {
                position++;

                // adding the string to the tokens
                TokenType type = TokenType::RIGHT_COMMENT;
                Token new_token = Token(type, ">>");
                tokens.push_back(new_token);
            }

            else
            {
                position++;
                
                // adding the string to the tokens
                TokenType type = TokenType::GREATER;
                Token new_token = Token(type, ">");
                tokens.push_back(new_token);
            }
        }

        else if(current_character == '<')
        {
            position++;
            current_character = code[position];
            
            if(current_character == '=')
            {
                position++;

                // adding the string to the tokens
                TokenType type = TokenType::LESS_EQUAL;
                Token new_token = Token(type, "<=");
                tokens.push_back(new_token);
            }
            
            else if(current_character == '<')
            {
                position++;

                // adding the string to the tokens
                TokenType type = TokenType::LEFT_COMMENT;
                Token new_token = Token(type, "<<");
                tokens.push_back(new_token);
            }

            else
            {
                position++;
                
                // adding the string to the tokens
                TokenType type = TokenType::LESS;
                Token new_token = Token(type, "<");
                tokens.push_back(new_token);
            }
        }

        else if (current_character == ' ' || current_character == '\n')
        {
            position++;
            continue;
        }

        // we have a invalid character in our code
        else 
        { 
          cout << "<Lexer Error> Unexpected character " + code[position] << " (LINE: " << line << ", COLUMN: " << position << "))"  << endl;
          exit(0);
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
        cout << "\tTYPE: " << token.get_type_name() << "\t VALUE: " << token.get_value();
        if (counter < tokens.size() - 1)
        {
            cout << " ," << endl;
        }

        counter++;
    }

    cout << endl; 
    cout << "}" << endl;
}