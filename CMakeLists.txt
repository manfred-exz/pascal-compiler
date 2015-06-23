cmake_minimum_required(VERSION 3.2)
project(pascal_compiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    assembler.c
    assembler.h
    globals.h
    main.c
    parse.h
    pascal.l
    pascal.y
    scan.h
    symtab.c
    symtab.h
    utils.c
    utils.h
    lex.yy.c
    y.tab.c
    y.tab.h )

add_executable(pascal_compiler ${SOURCE_FILES})