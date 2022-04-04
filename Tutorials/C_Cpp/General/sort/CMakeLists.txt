cmake_minimum_required(VERSION 2.4)
project(sort)

set(SORT_ROOT_DIR ..)

set(HEADERS merge.h quick.h insert.h common.h)
set(SOURCES main.c merge.c quick.c insert.c common.c)

add_compile_definitions(CMAKE_BUILD)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${SORT_ROOT_DIR})

# Link the 'common' folder to the executable as well as the common library
target_link_directories(${PROJECT_NAME} PRIVATE ${SORT_ROOT_DIR})