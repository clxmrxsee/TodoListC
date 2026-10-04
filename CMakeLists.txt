cmake_minimum_required(VERSION 4.3)
project(TodoList C)

set(CMAKE_C_STANDARD 11)

add_executable(TodoList main.c
        main.c
        data/database.c
        sqlite/sqlite3.c
        commands/commands.c
        commands/commands.h
        commands/add.c
        commands/add.h
)

target_include_directories(TodoList PRIVATE
        data
        sqlite
)