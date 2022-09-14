#include "../include/Alchemy.hpp"

Alchemy::Alchemy()
{
    file_path = "code.ach";
    read_file(file_path);
}

Alchemy::Alchemy(string file_path)
{
    this->file_path = file_path;
    read_file(file_path);
}

void Alchemy::run()
{
    /*cout << endl;
    cout << "ALCHEMY CODE: " << endl << code << endl;
    cout << endl;*/

    Lexer lexer = Lexer(code);
    vector<Token> tokens = lexer.tokenize();
    lexer.print_tokens();

    Parser parser = Parser(tokens);
    vector<SyntaxTree> tree = parser.parse();
    parser.print_syntax_tree();
}

string Alchemy::read_file(string file_path)
{   
    stringstream code_stream;
    string line;
    ifstream file (file_path);

    if(file.is_open())
    {
        code_stream << file.rdbuf();
        file.close();
    }

    else
    {
       cout << "Unable to open file: " << file_path << endl; 
    }

    code = code_stream.str();
    code.erase(remove(code.begin(), code.end(), '\r'), code.end());
    return code;
}

int main()
{
    Alchemy alchemy = Alchemy();
    alchemy.run();
    
    return 0;
};