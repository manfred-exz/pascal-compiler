#include "astree.h"

static FILE *treefile;
static int nspc;



void print_ast(TreeNode *parseTree, char * treename) {
    printf("print ast!\n");
    if(!(treefile = fopen(treename, "w+")))
        fprintf(stderr, "Could not write ast on %s; continuing\n", treename);
    else{
        print_program(parseTree);
        fclose(treefile);
    }
}

void print_program(TreeNode *parseTree) {
    if(parseTree == NULL)
        printf("Unable to print. The abstract syntax tree is empty.\n");
    print_indent();
    print_routine(parseTree);
}



void print_routine(TreeNode *routine) {
    if(routine != NULL){
        int i;
        const int n_child = sizeof(routine->child)/sizeof(routine->child[0]);

        print_start("routine");
        for(i = 0; i < n_child; i++){
            if(routine->child[i] != NULL){
                print_indent();
                print_routine_part(routine->child[i]);
            }
        }
        print_finish();
    }
}

void print_const_part(TreeNode *part){
    if(part == NULL)
        return;

    tree_print("[CONST] ");
    while(part != NULL){
        tree_print("id: %s = ", part->id);
         part = part->sibling;
    }
}


void print_routine_part(TreeNode *part) {
    if(part == NULL)
        return;

    switch(part->nodekind){
        case ConstDeclK:
            print_const_part(part);
            break;
        default:
            break;
    }

}


void tree_print(char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(treefile, fmt, args);
    va_end(args);
}

void print_indent(void) {
    tree_print("%-*c", nspc, '\n');
}


void print_start(char *s) {
    tree_print ("(%s", s);
    nspc += 2;
}

void print_finish() {
    tree_print (")");
    nspc -= 2;
}

/*

void print_id (IDENT *id)
{
    if (id)
        tree_print ("|%s|", id->id_chars);
}

void print_bind (BINDING *b)
{
    if (b) {
        DECL *d = b->bind_decl;
        print_id (b->bind_id);
        if (d) {
            SYMTAB *s = d->decl_symtab;
            tree_print (", number: %d", d->decl_number);
            if (s)
                tree_print (", scope: %d", s->symtab_number);
        }
    }
}

void print_op (int op)
{
    tree_print ("op(");
    switch(op) {
        case OR_ : tree_print ("OR" ); break;
        case AND_: tree_print ("AND"); break;
        case NOT_: tree_print ("NOT"); break;
        case LE_ : tree_print ("<=" ); break;
        case GE_ : tree_print (">=" ); break;
        case NE_ : tree_print ("<>" ); break;
        case DIV_: tree_print ("DIV"); break;
        case MOD_: tree_print ("MOD"); break;
        default  : tree_print ("%c", op); break;
    }
    tree_print(")");
}
 */
