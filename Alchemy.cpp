#include "Alchemy.hpp"
#include "Lexer.hpp"
//#include "../src/Token.cpp"



Alchemy::Alchemy(string code)
{
    this->code = code;
}

void Alchemy::run()
{
    cout << this->code << endl;

    Lexer lex = Lexer();
    list<Token> tokens = lex.tokenize(code);

    //for (Token token : tokens) {
    //    cout << '\t' << token.get_value();;
    //}

}

int main()
{
    string code = "print 'hello world'; \nprint 'hello again';";
    Alchemy alchemy = Alchemy(code);
    alchemy.run();
    
    return 0;
};