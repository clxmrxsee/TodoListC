cmake_minimum_required(VERSION 4.3)
project(TodoList C)

set(CMAKE_C_STANDARD 11)

add_executable(TodoList main.c
        main.c
        data/database.c
        sqlite/sqlite3.c
)

target_include_directories(TodoList PRIVATE
        data
        sqlite
)