#ifndef __M19_SEMANTICS_XMLWRITER_H__
#define __M19_SEMANTICS_XMLWRITER_H__

#include <string>
#include <iostream>
#include <cdk/ast/basic_node.h>
#include <cdk/symbol_table.h>
#include "targets/basic_ast_visitor.h"
#include "targets/symbol.h"

namespace m19 {

  class xml_writer: public basic_ast_visitor {
    cdk::symbol_table<m19::symbol> &_symtab;
    std::shared_ptr<m19::symbol> _function;

  public:
    xml_writer(std::shared_ptr<cdk::compiler> compiler, cdk::symbol_table<m19::symbol> &symtab) :
        basic_ast_visitor(compiler), _symtab(symtab), _function(nullptr){
    }

  public:
    ~xml_writer() {
      os().flush();
    }

  private:
    void openTag(const std::string &tag, int lvl) {
      os() << std::string(lvl, ' ') + "<" + tag + ">" << std::endl;
    }
    void openTag(const cdk::basic_node *node, int lvl) {
      openTag(node->label(), lvl);
    }
    void closeTag(const std::string &tag, int lvl) {
      os() << std::string(lvl, ' ') + "</" + tag + ">" << std::endl;
    }
    void closeTag(const cdk::basic_node *node, int lvl) {
      closeTag(node->label(), lvl);
    }

  protected:
    void do_binary_expression(cdk::binary_expression_node * const node, int lvl);
    void do_unary_expression(cdk::unary_expression_node * const node, int lvl);
    template<typename T>
    void process_literal(cdk::literal_node<T> * const node, int lvl) {
      os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->value() << "</" << node->label() << ">" << std::endl;
    }

  public:
  // DO NOT EDIT THESE LINES
#define __IN_VISITOR_HEADER__
#include "ast/visitor_decls.h"       // AUTOMATICALLY GENERATED
#undef __IN_VISITOR_HEADER__
  // DO NOT EDIT THESE LINES: END

  };

} // m19

#endif
