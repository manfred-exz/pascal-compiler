#include "astree.h"
#include "globals.h"

static FILE *treefile;
static int nspc;


void value_str(char *str, const TreeNode *node);

void node_str(char *str, TreeNode *typeNode);

void type_str(char *str, const TreeNode *node);

void simple_type_str(char *str, const TreeNode *node);

// print the structure of the tree

void print_ast(TreeNode *parseTree, char *treename) {
    printf("print ast!\n");
    if (!(treefile = fopen(treename, "w+")))
        fprintf(stderr, "Could not write ast on %s; continuing\n", treename);
    else {
        print_program(parseTree);
        fclose(treefile);
    }
}

void print_program(TreeNode *parseTree) {
    if (parseTree == NULL)
        printf("Unable to print. The abstract syntax tree is empty.\n");
    print_indent();
    print_routine(parseTree);
}

void print_routine(TreeNode *routine) {
    if (routine != NULL) {
        int i;
        const int n_child = sizeof(routine->child) / sizeof(routine->child[0]);

        print_start("routine");
        for (i = 0; i < n_child; i++) {
            if (routine->child[i] != NULL) {
                print_indent();
                print_routine_part(routine->child[i]);
            }
        }
        print_finish();
    }
}

void simple_type_str(char *str, const TreeNode *node) {
    // simple type
    char *simpleKindStr[8] = {"char", "integer", "real", "string",
                              "boolean", "id", "namelist", "dotdot"};

    char buf[20];
    char buf1[20], buf2[20];

    SimpleKind kind = node->kind.simple_kind;
    strcpy(buf, simpleKindStr[kind]);

    switch (kind){
        case IdK:
            sprintf(str, "ID: %s", node->id);
            break;
        case DotDotK:
            node_str(buf1, node->child[0]); //dotL
            node_str(buf2, node->child[1]); //dotR
            sprintf(str, "%s .. %s", buf1, buf2);
            break;
        case SNameListK:

            break;
        default:
            strcpy(str, buf);
            break;
    }
}

void value_str(char *str, const TreeNode *node) {
    SimpleKind kind = node->kind.simple_kind;

    switch (kind) {
        case IntegerK:
            sprintf(str, "int:%d", node->value.int_value);
            break;
        case RealK:
            sprintf(str, "real:%.2lf", node->value.real_value);
            break;
        case CharK:
            sprintf(str, "char:%d", node->value.int_value);
            break;
        case StringK:
            sprintf(str, "string:%s", node->value.str_value);
            break;
        case BooleanK:
            sprintf(str, "boolean:%d", node->value.int_value);
            break;
        default:
            sprintf(str, "[ERR] unknown const value type, cannot print this value.");
            break;
    }
    return;
}


void type_str(char *str, const TreeNode *node) {
    TypeKind kind = node->kind.type_kind;
    char buf1[255], buf2[255];

    switch (kind) {
        case TypeSimpleK:
            node_str(str, node->child[0]);  //type
            break;
        case TypeArrayK:
            node_str(buf1, node->child[0]); //array range
            node_str(buf2, node->child[1]); //array element type
            sprintf(str, "array[%s] of %s", buf1, buf2);
            break;
        case TypeRecordK:
            break;
        default:
            sprintf(str, "[ERR] unknown type, cannot print this value.");
            break;
    }
}


void node_str(char *str, TreeNode *typeNode) {

    // constant value
    if (typeNode->nodekind == ConstK) {
        value_str(str, typeNode);
        return;
    }

    if (typeNode->nodekind == SimpleK) {
        simple_type_str(str, typeNode);
        return;
    }

    if (typeNode->nodekind == TypeK) {
        type_str(str, typeNode);
        return;
    }

    return;
}


void print_const_part(TreeNode *part) {
    if (part == NULL)
        return;

    char buf[255];
    TreeNode *constNode;

    print_start("[const part]");
    while (part != NULL) {
        constNode = part->child[0]; //const value node
        node_str(buf, constNode);

        print_indent();
        tree_print("ID: {%s} = {%s}", part->id, buf);
        part = part->sibling;
    }
    print_finish();
}

void print_type_part(TreeNode *part) {
    if (part == NULL)
        return;

    char buf[255];
    TreeNode *typeNode;

    print_start("[type part]");
    // the Node 'part' is also a type decl node
    while (part != NULL) {
        typeNode = part->child[0];
        node_str(buf, typeNode);

        print_indent();
        tree_print("ID: {%s} is of type {%s}", part->id, buf);
        part = part->sibling;
    }
    print_finish();
}

// part: every non-empty routine part.
void print_routine_part(TreeNode *part) {
    if (part == NULL)
        return;

    switch (part->nodekind) {

        case ConstDeclK:
            print_const_part(part);
            break;
        case TypeDeclK:
            print_type_part(part);
            break;

        default:
            break;
    }

}


void tree_print(char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    //vfprintf(treefile, fmt, args);
    vfprintf(stdout, fmt, args);
    va_end(args);
}

void print_indent(void) {
    tree_print("%-*c", nspc, '\n');
}


void print_start(char *s) {
    tree_print("(%s", s);
    nspc += 2;
}

void print_finish() {
    tree_print(")");
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
