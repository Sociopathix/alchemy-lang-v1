#include "../include/Alchemy.hpp"

Alchemy::Alchemy(string code)
{
    this->code = code;
}

void Alchemy::run()
{
    cout << endl;
    cout << "ALCHEMY CODE: " << this->code << endl;
    cout << endl;

    Lexer lex = Lexer(code);
    vector<Token> tokens = lex.tokenize();
    lex.print_tokens();
}

int main()
{
    string code = "print \"hello world\";";
    Alchemy alchemy = Alchemy(code);
    alchemy.run();
    
    return 0;
};