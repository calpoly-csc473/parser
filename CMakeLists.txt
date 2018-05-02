cmake_minimum_required(VERSION 2.8)

project(parser)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
	lib/Tokenizer.cpp
	lib/TokenStream.cpp
	lib/Parser.cpp
)

set(HEADERS
	ext/catch.hpp
	lib/parse_error.hpp
	lib/Tokenizer.hpp
	lib/TokenStream.hpp
	lib/Parser.hpp
)

add_library(parselib ${SOURCES} ${HEADERS})

add_executable(parser src/Main.cpp)
target_include_directories(parser PUBLIC "ext/")
target_include_directories(parser PUBLIC "lib/")
target_link_libraries(parser parselib)

add_executable(unit_tests test/Tests.cpp)
target_include_directories(unit_tests PUBLIC "ext/")
target_include_directories(unit_tests PUBLIC "lib/")
target_link_libraries(unit_tests parselib)

enable_testing()
add_test(test_all unit_tests)
