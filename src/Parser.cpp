#include "../include/Parser.hpp"

Parser::Parser(vector<Token> tokens)
{
    this->tokens = tokens;
}

bool Parser::parse()
{
    const int length = tokens.size();
    int position = 0;
    int line = 0;

    while(position < length)
    {
        Token token = tokens[position];

        // If the token is the print keyword.
        if(token.get_type() == TokenType::KEYWORD and token.get_value() == "print")
        {
            
            switch(tokens[position + 1].get_type()) 
            {
                case TokenType::SEMICOLON:
                    cout << "Parser Error: Unexpected end of line, expected string! (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
                    return false;
                
                case TokenType::END_FILE:
                    cout << "Parser Error: Unexpected end of file, expected string! (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
                    return false;
                
                case not TokenType::STRING:
                    cout << "Parser Error: Unexpected token " << tokens[position + 1].get_type_name() << " expected string! (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
                    return false;
                
                default:
                    // If at least one string has been added, continue.            
                    cout << tokens[position + 1].get_value(); // Add endl here?
                    position += 2; // Increment by 2, for print and string.

                    if (tokens[position].get_type() == TokenType::SEMICOLON)
                    {
                        cout << endl;
                        position++;
                        line++;
                        continue;
                    }
            }

            // Old if/else statment, keeping here for now just in case.
            /*if(tokens[position + 1].get_type() == TokenType::SEMICOLON) // If next token is semicolon / end of line.
            {
                cout << "Parser Error: Unexpected end of line, expected string! (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
                return false;
            }

            else if(tokens[position + 1].get_type() == TokenType::END_FILE) // If next token is end of file.
            {
                cout << "Parser Error: Unexpected end of file, expected string! (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
                return false;
            }

            else if(tokens[position + 1].get_type() != TokenType::STRING) // Check if next token is not a string.
            {
                cout << "Parser Error: Unexpected token " << tokens[position + 1].get_type_name() << " expected string! (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
                return false;
            }

            // If at least one string has been added, continue.            
            cout << tokens[position + 1].get_value(); // Add endl here?
            position += 2; // Increment by 2, for print and string.
            
           
            if (tokens[position].get_type() == TokenType::SEMICOLON)
            {
                cout << endl;
                position++;
                line++;
                continue;
            }*/
        }

        else if(token.get_type() == TokenType::END_FILE)
        {
            return true;
        }

        else
        {
            cout << "Parser Error: Unexpected token " << token.get_type_name() << "! (LINE: " << line << ", COLUMN: " << position << ")"  << endl;
            break;
        }
    }

    return false;
}