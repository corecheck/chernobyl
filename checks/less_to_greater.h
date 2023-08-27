#pragma once

#include "common.h"
using namespace clang::transformer;
using namespace clang::tidy::utils;
using namespace clang::ast_matchers;

namespace clang::tidy::mutator {
    class MutatorLessToGreater : public TransformerClangTidyCheck {
       public:
        MutatorLessToGreater(StringRef Name, ClangTidyContext *Context)
            : TransformerClangTidyCheck(
                  makeRule(
                      binaryOperator(hasOperatorName(">"), hasLHS(expr().bind("lhs")), hasRHS(expr().bind("rhs"))),
                      changeTo(cat(node("lhs"), " < ", node("rhs"))),
                      cat("> mutated to <")),
                  Name,
                  Context) { }
    };

}  // namespace clang::tidy::mutator