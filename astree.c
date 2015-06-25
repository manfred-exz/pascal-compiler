#include "astree.h"
#include "globals.h"

static FILE *treefile;
static int nspc;


void value_str(const TreeNode *node);

void node_str(TreeNode *typeNode);

void type_str(TreeNode *node);

void simple_type_str(const TreeNode *node);

void name_list_str(TreeNode *name_list_node);

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

        // if routine is empty, don't print it.
        int is_empty = 1;
        for(i = 0; i < n_child; i++){
            if(routine->child[i] != NULL)
                is_empty = 0;
        }
        if(is_empty == 1)
            return;

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

void simple_type_str(const TreeNode *node) {
    // simple type
    char *simpleKindStr[8] = {"char", "integer", "real", "string",
                              "boolean", "id", "namelist", "dotdot"};


    SimpleKind kind = node->kind.simple_kind;
    if (kind != DotDotK && kind != NameListK && kind != IdK)
        tree_print(simpleKindStr[kind]);

    switch (kind) {
        case IdK:
            tree_print("%s", node->id);
            break;
        case DotDotK:
            node_str(node->child[0]); //dotL
            tree_print(" .. ");
            node_str(node->child[1]); //dotR
            break;
        case SNameListK:
            name_list_str(node->child[0]);
            break;
        default:
            break;
    }
}

void value_str(const TreeNode *node) {
    SimpleKind kind = node->kind.simple_kind;
    char flag = '+';

    switch (kind) {
        case IntegerK:
            if (node->is_minus)
                flag = '-';
//            sprintf(str, "int:%c%d", flag, node->value.int_value);
            tree_print("int:%c%d", flag, node->value.int_value);
            break;
        case RealK:
            if (node->is_minus)
                flag = '-';
            tree_print("real:%c%.2lf", flag, node->value.real_value);
//            sprintf(str, "real:%c%.2lf", flag, node->value.real_value);
            break;
        case CharK:
            if (node->is_minus)
                flag = '-';
            tree_print("char:%c%d", flag, node->value.int_value);
//            sprintf(str, "char:%c%d", flag, node->value.int_value);
            break;
        case StringK:
            tree_print("string:%s", node->value.str_value);
//            sprintf(str, "string:%s", node->value.str_value);
            break;
        case BooleanK:
            tree_print("boolean:%d", node->value.int_value);
//            sprintf(str, "boolean:%d", node->value.int_value);
            break;
        default:
            tree_print("[ERR] unknown const value type, cannot print this value.");
//            sprintf(str, "[ERR] unknown const value type, cannot print this value.");
            break;
    }
    return;
}


void type_str(TreeNode *node) {
    TypeKind kind = node->kind.type_kind;

    switch (kind) {
        case TypeSimpleK:
            node_str(node->child[0]);  //type
            break;
        case TypeArrayK:
            tree_print("array[");
            node_str(node->child[0]); //array range
            tree_print("] of ");
            node_str(node->child[1]); //array element type
            break;
        case TypeRecordK:
            node_str(node->child[0]);
            break;
        default:
            tree_print("[ERR] unknown type, cannot print this value.");
            break;
    }
}


void name_list_str(TreeNode *name_list_node) {
    int is_first_time = 1;
    tree_print("(");

    while (name_list_node != NULL) {
        if (is_first_time)
            tree_print("%s", name_list_node->id);
        else
            tree_print(", %s", name_list_node->id);

        is_first_time = 0;
        name_list_node = name_list_node->sibling;
    }

    tree_print(")");
}

void record_str(TreeNode *filedNode) {
    print_indent();
    print_start("recoard");

    while (filedNode != NULL) {
        print_indent();
        node_str(filedNode->child[0]);
        node_str(filedNode->child[1]);

        filedNode = filedNode->sibling;
    }

    nspc -= 2;
    print_indent();
    tree_print("end;");
    nspc += 2;
    print_finish();
}

void var_str(TreeNode *var_decl_node) {
    tree_print("Var: ");
    node_str(var_decl_node->child[0]);
    tree_print(" is of type: ");
    node_str(var_decl_node->child[1]);
    tree_print(";");
}

void params_str(TreeNode *param_node) {
    print_indent();
    print_start("parameter");
    while(param_node != NULL) {
        print_indent();
        node_str(param_node->child[0]);     // name_list
        tree_print(": ");
        node_str(param_node->child[1]);     // type
        tree_print(";");

        param_node = param_node->sibling;
    }
    print_finish();
}

void node_str(TreeNode *typeNode) {

    // constant value
    if (typeNode->nodekind == ConstK) {
        value_str(typeNode);
        return;
    }

    if (typeNode->nodekind == SimpleK) {
        simple_type_str(typeNode);
        return;
    }

    if (typeNode->nodekind == TypeK) {
        type_str(typeNode);
        return;
    }

    if (typeNode->nodekind == NameListK) {
        name_list_str(typeNode);
        return;
    }

    if (typeNode->nodekind == RecordK) {
        record_str(typeNode);
        return;
    }

    if (typeNode->nodekind == VarDeclK){
        var_str(typeNode);
        return;
    }

    if(typeNode->nodekind == ParaK){
        params_str(typeNode);
        return;
    }

    if(typeNode->nodekind == RoutineK){
        print_routine(typeNode);
        return;
    }

    return;
}

void print_const_part(TreeNode *part) {
    if (part == NULL)
        return;

    TreeNode *constNode;

    print_start("[const part]");
    while (part != NULL) {
        constNode = part->child[0]; //const value node
        print_indent();
        tree_print("Const: {%s} = ", part->id);

        node_str(constNode);

        part = part->sibling;
    }
    print_finish();
}

void print_type_part(TreeNode *part) {
    if (part == NULL)
        return;

    TreeNode *typeNode;

    print_start("[type part]");
    // the Node 'part' is also a type decl node
    while (part != NULL) {
        typeNode = part->child[0];
        print_indent();
        tree_print("Type: {%s} is of type ", part->id);

        node_str(typeNode);

        part = part->sibling;
    }
    print_finish();
}

void print_var_part(TreeNode *part) {
    if (part == NULL)
        return;

    print_start("[var part]");
    // the Node 'part' is also a type decl node
    while (part != NULL) {
        print_indent();

        node_str(part);

        part = part->sibling;
    }
    print_finish();
}

void print_func_part(TreeNode *func_proc_node) {
    if (func_proc_node == NULL)
        return;

    print_start("[routine part]");
    while (func_proc_node != NULL) {
        print_indent();

        if(func_proc_node->kind.func_proc_kind == FuncK){
            tree_print("Function: {%s}", func_proc_node->id);

            node_str(func_proc_node->child[0]); // parameters
            print_indent();
            tree_print("(return-type: ");
            node_str(func_proc_node->child[1]); // function return type
            tree_print(")");
            tree_print(";");
            print_indent();
            node_str(func_proc_node->child[2]); // function body
            tree_print(";");
        }
        else if(func_proc_node->kind.func_proc_kind == ProcK){
            tree_print("Procedure: {%s}", func_proc_node->id);

            node_str(func_proc_node->child[0]); // parameters
            print_indent();
            tree_print(";");
            print_indent();
            node_str(func_proc_node->child[1]); // function body
            tree_print(";");
        }
        else
            tree_print("unknown routine type, neither function or procedure\n");



        func_proc_node = func_proc_node->sibling;
    }
    print_finish();
}

/* todo: compound_stmt */
void print_comp_part(TreeNode *comp_node) {
    if(comp_node == NULL)
        return;

    print_start("[compound stmt]");

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
        case VarDeclK:
            print_var_part(part);
            break;
        case FuncProcK:
            print_func_part(part);
            break;
        case StmtK:
            print_comp_part(part);
            break;

        default:
            break;
    }

}


void tree_print(char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stdout, fmt, args);
    /*!!debug!!*/
    fflush(stdout);
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