//
// Created by manfred on 15-6-24.
//

#ifndef PASCAL_COMPILER_ASTREE_H
#define PASCAL_COMPILER_ASTREE_H
#include <stdarg.h>
#include "globals.h"

void print_ast(TreeNode *parseTree, char * treename);
void print_program(TreeNode *pNode);
void print_indent(void);
void tree_print(char *fmt, ...);
void print_start(char *s);
void print_routine(TreeNode *routine);
void print_finish();
void print_routine_part(TreeNode *part);



#endif //PASCAL_COMPILER_ASTREE_H
