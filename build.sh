#! /bin/bash

yacc -d pascal.y
flex pascal.l
gcc -c lex.yy.c
gcc -c y.tab.c
gcc -c utils.c
gcc -c symtab.c
gcc -c assembler.c
gcc -c main.c
gcc -o compiler main.o lex.yy.o y.tab.o utils.o symtab.o assembler.o -lfl

./clean.sh
