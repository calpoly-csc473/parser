cmake_minimum_required(VERSION 2.8)

project(parser)

if(WIN32)
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

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

add_executable(sceneinfo src/SceneInfo.cpp)
target_include_directories(sceneinfo PUBLIC "lib/")
target_link_libraries(sceneinfo parselib)

add_executable(unit_tests test/Tests.cpp)
target_include_directories(unit_tests PUBLIC "ext/")
target_include_directories(unit_tests PUBLIC "lib/")
target_link_libraries(unit_tests parselib)

enable_testing()
add_test(test_all unit_tests)
