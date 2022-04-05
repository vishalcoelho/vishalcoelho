cmake_minimum_required(VERSION 2.4)
project(bst)

set(BST_ROOT_DIR ..)

set(HEADERS bst.h)
set(SOURCES bst.c)

add_compile_definitions(CMAKE_BUILD)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${BST_ROOT_DIR})

# Link the 'common' folder to the executable as well as the common library
target_link_directories(${PROJECT_NAME} PRIVATE ${BST_ROOT_DIR})
