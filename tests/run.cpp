#include "../src/toyparser.hpp"


int main()
{
    Parser parser;
    const string src {"42"};

    boost::json::object info;
    
    if (ASTNode *ast_root = parser.parse(src))
      pretty_print(cout, ast_root->getInfo());
    return 0;
}