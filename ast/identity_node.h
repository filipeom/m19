#ifndef __M19_IDENTITY_H__
#define __M19_IDENTITY_H__

#include <cdk/ast/unary_expression_node.h>
#include "targets/basic_ast_visitor.h"

namespace m19 {

  class identity_node: public cdk::unary_expression_node {

  public:
    identity_node(int lineno, cdk::expression_node *argument) :
        cdk::unary_expression_node(lineno, argument) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_identity_node(this, level);
    }

  };

} // m19

#endif
