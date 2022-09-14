#include "../include/SyntaxTree.hpp"

SyntaxTree::SyntaxTree(SyntaxTreeType type)
{
    this->type = type;
}

string SyntaxTree::get_type_name()
{
    string type_names[] = {
        "SYN_ASSIGNMENT", "SYN_BINARY", "SYN_CALL",
        "SYN_IDENTIFIER", "SYN_IF", "SYN_NUMBER",
        "SYN_PRINT", "SYN_PROGRAM", "SYN_STRING"
    };

    string type_name = type_names[type];
    return type_name;
}