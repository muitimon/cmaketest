cmake_minimum_required(VERSION 3.10)
project(hello)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(hello
    src/hello.cpp
    src/hello.h)
target_compile_options(hello PRIVATE
    $<$<CXX_COMPILER_ID:Clang>:
        -Wcomma
        -Wextra-semi
        -Wimplicit-fallthrough
        -Wmost
        -Wmove
        -Wnewline-eof
    >

    $<$<CXX_COMPILER_ID:GNU>:
        -pedantic
    >

    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall
        -Werror
        -Wextra
        -Wnon-virtual-dtor
        $<$<CONFIG:DEBUG>:-g;-O0>
        $<$<CONFIG:RELEASE>:-O3>
    >

    $<$<CXX_COMPILER_ID:MSVC>:
        /W4
        /WX
        $<$<CONFIG:DEBUG>:/Od;/MTd>
        $<$<CONFIG:RELEASE>:/O2;/Ob2;/MT>
    >)

add_executable(test
    test/catch.hpp
    test/hello_test.cpp
    test/main.cpp)
target_compile_options(test PRIVATE
    $<$<CXX_COMPILER_ID:Clang>:
        -Wcomma
        -Wextra-semi
        -Wimplicit-fallthrough
        -Wmost
        -Wmove
        -Wnewline-eof
    >

    $<$<CXX_COMPILER_ID:GNU>:
        -pedantic
    >

    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall
        -Werror
        -Wextra
        -Wnon-virtual-dtor
        $<$<CONFIG:DEBUG>:-g;-O0>
        $<$<CONFIG:RELEASE>:-O3>
    >

    $<$<CXX_COMPILER_ID:MSVC>:
        /W4
        /WX
        $<$<CONFIG:DEBUG>:/Od;/MTd>
        $<$<CONFIG:RELEASE>:/O2;/Ob2;/MT>
    >)
target_include_directories(test PRIVATE
    src)
target_link_libraries(test hello)

add_executable(tool
    tool/main.cpp)
target_compile_options(tool PRIVATE
    $<$<CXX_COMPILER_ID:Clang>:
        -Wcomma
        -Wextra-semi
        -Wimplicit-fallthrough
        -Wmost
        -Wmove
        -Wnewline-eof
    >

    $<$<CXX_COMPILER_ID:GNU>:
        -pedantic
    >

    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall
        -Werror
        -Wextra
        -Wnon-virtual-dtor
        $<$<CONFIG:DEBUG>:-g;-O0>
        $<$<CONFIG:RELEASE>:-O3>
    >

    $<$<CXX_COMPILER_ID:MSVC>:
        /W4
        /WX
        $<$<CONFIG:DEBUG>:/Od;/MTd>
        $<$<CONFIG:RELEASE>:/O2;/Ob2;/MT>
    >)
target_include_directories(tool PRIVATE
    src)
target_link_libraries(tool hello)
