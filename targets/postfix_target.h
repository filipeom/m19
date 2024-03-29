#ifndef __M19_SEMANTICS_POSTFIX_TARGET_H__
#define __M19_SEMANTICS_POSTFIX_TARGET_H__

#include <cdk/basic_target.h>
#include <cdk/symbol_table.h>
#include <cdk/ast/basic_node.h>
#include <cdk/compiler.h>
#include <cdk/emitters/postfix_ix86_emitter.h>
#include "targets/postfix_writer.h"
#include "targets/symbol.h"

namespace m19 {

  class postfix_target: public cdk::basic_target {
    static postfix_target _self;

  private:
    postfix_target() :
        cdk::basic_target("asm") {
    }

  public:
    bool evaluate(std::shared_ptr<cdk::compiler> compiler) {
      // THIS SYMBOL TABLE WILL BE USED TO CHECK IDENTIFIERS
      // DURING CODE GENERATION
      cdk::symbol_table<m19::symbol> symtab;

      // THIS IS THE BACKEND POSTFIX MACHINE
      cdk::postfix_ix86_emitter pf(compiler);

      // GENERATE ASSEMBLY CODE FROM THE SYNTAX TREE
      postfix_writer writer(compiler, symtab, pf);
      compiler->ast()->accept(&writer, 0);

      return true;
    }

  };

} // m19

#endif
