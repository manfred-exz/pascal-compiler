cmake_minimum_required(VERSION 3.2)
project(pascal_compiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c89")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES
    astree.c
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

add_executable(pascal_compiler ${SOURCE_FILES} astree.h)