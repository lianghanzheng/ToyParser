class ASTNode {
private:
  string type;
};

class NumLiteralNode: public ASTNode {
public:
  NumLiteralNode(string value)
    : type("NumericLiteral"),
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
    this.src = src;

    // Parse recursively starting from main entry
    // TODO: 

    return this.program();
  }

  /**
   * Main entty.
   *
   * Program
   *   : NumericalLiteral
   *   ;
   */
  ASTNode *Program() {
    return this.NumericLiteral();
  }

  /**
   * Numerical
   *   : NUMBER
   *   ;
   */
  ASTNode *NumericLiteral() {
    // TODO: Use src to initilize a NumLiteralNode
    //       and return its pointer
  }
  
private:
    string src;
};
