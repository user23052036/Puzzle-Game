cmake_minimum_required(VERSION 3.24)
project(Puzzle-Game)


#out project
set(SOURCE_FILES
    code/main.c
    code/algorithm.c
    code/cheak.c
    code/display.c
    code/free.c
    code/numgen.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})