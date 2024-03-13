cmake_minimum_required(VERSION 3.5)

project(asan_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/bugfactory.h
    src/bugfactory.cpp
    src/abstractbug.h
    src/bugs.h
    src/bugs.cpp
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
    asan
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address -fsanitize=leak -g")
