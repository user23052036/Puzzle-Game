cmake_minimum_required(VERSION 3.24)
project(Puzzle-Game)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(SOURCE_FILES
    code/main.c
    code/algorithm.c
    code/cheak.c
    code/display.c
    code/levels.c
    code/free.c
    code/numgen.c
    code/getkey.c)

include_directories(code)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Check if the system is Unix-like (including macOS and Linux)
if(UNIX)
    # Link the math library only for Unix-like systems
    target_link_libraries(${PROJECT_NAME} m)
endif()

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()
