
// Copyright (C) 2018 Ian Dunn
// For conditions of distribution and use, see the LICENSE file


#include "Tokenizer.hpp"
#include "Parser.hpp"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <vector>
using namespace std;
using namespace parser;


TEST_CASE( "Tokenizer" )
{
	CHECK( Tokenizer::Tokenize("") == vector<string>{} );
	CHECK( Tokenizer::Tokenize("{}") == vector<string>{ "{", "}" } );
	CHECK( Tokenizer::Tokenize("{abcd def}") == vector<string>{ "{", "abcd", "def", "}" } );
	CHECK( Tokenizer::Tokenize("{abcd def ghi}") == vector<string>{ "{", "abcd", "def", "ghi", "}" } );
	CHECK( Tokenizer::Tokenize("{abcd def3.10}") == vector<string>{ "{", "abcd", "def", "3.10", "}" } );
}

TEST_CASE( "Parser" )
{
	TokenStream ts;

	ts.reset(Tokenizer::Tokenize("<3, 4, 5>"));
	vec3 v1 = Parser::ParseVector3(ts);
	CHECK( v1.x == 3 );
	CHECK( v1.y == 4 );
	CHECK( v1.z == 5 );

	ts.reset(Tokenizer::Tokenize("<7, 8, 9, 10.5>"));
	vec4 v2 = Parser::ParseVector4(ts);
	CHECK( v2.x == 7 );
	CHECK( v2.y == 8 );
	CHECK( v2.z == 9 );
	CHECK( v2.w == 10.5 );
}
