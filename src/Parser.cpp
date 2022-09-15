#include "../include/Parser.hpp"

// NOTES:
/*  var num = 1; 
    print(num);

    {
        type : SyntaxTreeType::ASSIGNMENT
        operator : =
        left (ast) : 
        {
            type : SyntaxTreeType::IDENTIFIER
            value : "num"
        }
        right (ast) : 
        {
            type : SyntaxTreeType::NUMBER
            value : 1
        }
    }

    {
        type : SyntaxTreeType::PRINT
        args : 
        [
            {
                type : SyntaxTreeType::IDENTIFIER
                value : "num"
            }
        ]
    }

    Types of ASTs:

    number 
    {
        type : NUMBER, 
        value : TokenType::NUMBER
    }

    string 
    {
        type : STRING, 
        value : TokenType::STRING
    }

    identifier 
    {
        type : IDENTIFIER, 
        value : NAME
    }

    print 
    {
        type : PRINT, 
        args : [ASTs...]
    }

    call 
    {
        type : CALL, 
        func : 
        {
            type : IDENTIFIER,
            value : TokenType::STRING
        }, 
        args : [ASTs...]
    }

    if
    {
        type : IF,
        condition(s) : ASTs
        then : AST,
        else : AST
    }

    assignment
    {
        type : ASSIGNMENT,
        operator : "=",
        left : AST,
        right : AST
    }

    binary (operation)
    {
        type : BINARY,
        operator : OPERATOR,
        left : AST,
        right : AST
    }

    program
    {
        type : PROGRAM
        body : [ASTs...]
    }

    */

// Class contructor.
Parser::Parser(vector<Token> tokens)
{
    this->tokens = tokens;
}

// Main parse function.
vector<SyntaxTree> Parser::parse()
{
    current_token = this->tokens.front();
    position = 0;

    while(current_token.get_type() != TokenType::END_FILE)
    {
        syntax_tree.push_back(parse_expression());
        increment_next();
    }

    print_syntax_tree();
    return syntax_tree;
}

// Parse the token in current_token.
SyntaxTree Parser::parse_expression()
{
    return SyntaxTree(SyntaxTreeType::SYN_IDENTIFIER);
}

// Increment current_token to the next in tokens.
void Parser::increment_next()
{
    position++;
    current_token = tokens[position];
}

void Parser::print_syntax_tree()
{
    for(SyntaxTree st : syntax_tree)
    {
        cout << st.get_type_name() << endl;
    }  
}