#ifndef __M19_BREAK_H__
#define __M19_BREAK_H__

#include <cdk/ast/basic_node.h>

namespace m19 {

  class break_node: public cdk::basic_node {

  public:
    break_node(int lineno) :
        cdk::basic_node(lineno) {
    }

  public:

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_break_node(this, level);
    }

  };

} // gr8

#endif
