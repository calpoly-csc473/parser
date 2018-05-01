
#include "Parser.hpp"
#include "Tokenizer.hpp"

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <vector>
using namespace std;


TEST_CASE( "Tokenizer" )
{
	CHECK( Tokenizer::Tokenize("") == vector<string>{} );
	CHECK( Tokenizer::Tokenize("{}") == vector<string>{ "{", "}" } );
	CHECK( Tokenizer::Tokenize("{abcd def}") == vector<string>{ "{", "abcd", "def", "}" } );
	CHECK( Tokenizer::Tokenize("{abcd def ghi}") == vector<string>{ "{", "abcd", "def", "ghi", "}" } );
	CHECK( Tokenizer::Tokenize("{abcd def3.10}") == vector<string>{ "{", "abcd", "def", "3.10", "}" } );
}
