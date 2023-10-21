#include <iostream>
#include <string>
#include "boost/json/src.hpp"

using namespace std;
namespace json = boost::json;

void
pretty_print( std::ostream& os, json::value const& jv, std::string* indent = nullptr )
{
    std::string indent_;
    if(! indent)
        indent = &indent_;
    switch(jv.kind())
    {
    case json::kind::object:
    {
        os << "{\n";
        indent->append(4, ' ');
        auto const& obj = jv.get_object();
        if(! obj.empty())
        {
            auto it = obj.begin();
            for(;;)
            {
                os << *indent << json::serialize(it->key()) << " : ";
                pretty_print(os, it->value(), indent);
                if(++it == obj.end())
                    break;
                os << ",\n";
            }
        }
        os << "\n";
        indent->resize(indent->size() - 4);
        os << *indent << "}";
        break;
    }

    case json::kind::array:
    {
        os << "[\n";
        indent->append(4, ' ');
        auto const& arr = jv.get_array();
        if(! arr.empty())
        {
            auto it = arr.begin();
            for(;;)
            {
                os << *indent;
                pretty_print( os, *it, indent);
                if(++it == arr.end())
                    break;
                os << ",\n";
            }
        }
        os << "\n";
        indent->resize(indent->size() - 4);
        os << *indent << "]";
        break;
    }

    case json::kind::string:
    {
        os << json::serialize(jv.get_string());
        break;
    }

    case json::kind::uint64:
    case json::kind::int64:
    case json::kind::double_:
        os << jv;
        break;

    case json::kind::bool_:
        if(jv.get_bool())
            os << "true";
        else
            os << "false";
        break;

    case json::kind::null:
        os << "null";
        break;
    }

    if(indent->empty())
        os << "\n";
}

class ASTNode {
public:
  ASTNode(string type_name)
    : info() { this->info["type_name"] = type_name; }
  boost::json::object getInfo() { return this->info; }

protected:
  boost::json::object info;
};

class NumLiteralNode: public ASTNode {
public:
  NumLiteralNode(string value)
    : ASTNode("NumLiteral") { this->info["value"] = value; }
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
