#include "globals.h"
#include "parse.h"
#include "assembler.h"
#include "astree.h"

int lineno;

FILE *source;
FILE *code;

TreeNode *parseTree;

int main(int argc, char **argv)
{
	if(argc < 3){
		printf("too few arguments! exiting.");
		return 1;
	}

	source = fopen(argv[1], "r");
    if(source == NULL){
        printf("unable to open pascal file. exiting.");
        return 1;
    }

	parseTree = parse();
    print_ast(parseTree, "parse");
	fclose(source);
	code = fopen(argv[2], "w");
    if(code == NULL){
        printf("unable to open dest asm file. exiting.");
    }

	assembler(parseTree);
	fclose(code);
	return 0;
}
