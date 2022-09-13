#include "../include/Parser.hpp"

Parser::Parser(vector<Token> tokens)
{
    this->tokens = tokens;
}

bool Parser::parse()
{
    const int length = tokens.size();
    int position = 0;
    int line = 1;
    stringstream output;

    cout << endl << "<BOF Started>" << endl << endl;

    while(position < length)
    {
        Token token = tokens[position];

        // If the token is the print keyword.
        if(token.get_type() == TokenType::KEYWORD and token.get_value() == "print")
        {
            switch(tokens[position + 1].get_type()) 
            {
                case TokenType::SEMICOLON:

                    cout << "<Parser Error> Unexpected end of line, expected string! (LINE: " << line << ", TOKEN: " << position  % line + 1 << ")"  << endl;
                    return false;
                
                case TokenType::END_FILE:

                    cout << "<Parser Error> Unexpected end of file, expected string! (LINE: " << line << ", TOKEN: " << position  % line + 1 << ")"  << endl;
                    return false;
                
                case TokenType::STRING:

                    // If at least one string has been added, continue.            
                    output << tokens[position + 1].get_value();
                    position += 2; // Increment by 2, for print and string.
                    break;
                
                default:

                    cout << "<Parser Error> Unexpected token " << tokens[position + 1].get_type_name() << " expected string! (LINE: " << line << ", TOKEN: " << position  % line + 1 << ")"  << endl;
                    return false;
            }

            if (tokens[position].get_type() == TokenType::SEMICOLON)
            {
                cout << output.str() << endl;
                output.str("");
                output.clear();
                position++;
                line++;
                continue;
            }

            else
            {
                cout << "<Parser Error> No EOL in line, expected semicolon! (LINE: " << line << ", TOKEN: " << position % line + 1 << ")"  << endl;
                return false;
            }

            return false;
        }

        else if(token.get_type() == TokenType::END_FILE)
        {
            cout << endl << "<EOF Reached>" << endl;
            return true;
        }

        else
        {
            cout << "<Parser Error> Unexpected token " << token.get_type_name() << "! (LINE: " << line << ", TOKEN: " << position % line + 1 << ")"  << endl;
            return false;
        }
    }

    return false;
}