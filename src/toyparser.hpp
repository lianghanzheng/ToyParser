#include <iostream>
#include <string>

using namespace std;

class ASTNode {
public:
  ASTNode(string type_name): type_name(type_name) {};

protected:
  string type_name;
};

class NumLiteralNode: public ASTNode {
public:
  NumLiteralNode(string value)
    : ASTNode("NumLiteral"),
      value(value) {};
private:
  string value;  
};

/**
 * Parser for letter syntax: 
 *   recursive descent implementation
 */
class Parser {
public:
  Parser() = default;
  /**
   * Parses a string into an AST.
   */
  ASTNode *parse(string src) {
    this->src = src;

    // Parse recursively starting from main entry
    // TODO: 

    return this->program();
  }

  /**
   * Main entty.
   *
   * Program
   *   : NumericalLiteral
   *   ;
   */
  ASTNode *program() {
    return this->NumericLiteral();
  }

  /**
   * Numerical
   *   : NUMBER
   *   ;
   */
  ASTNode *NumericLiteral() {
    return new NumLiteralNode(this->src);
  }
  
private:
    string src;
};
