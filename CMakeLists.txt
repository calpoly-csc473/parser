cmake_minimum_required(VERSION 2.8)

project(parser)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
	src/Tokenizer.cpp
	src/TokenStream.cpp
	src/Parser.cpp
	src/Test.cpp
)

set(HEADERS
	ext/catch.hpp
	src/parse_error.hpp
	src/Tokenizer.hpp
	src/TokenStream.hpp
	src/Parser.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC "ext/")
