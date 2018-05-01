
#include "Tokenizer.hpp"

#include <cctype>

using namespace std;


vector<string> Tokenizer::Tokenize(const string & source)
{
	vector<string> Result;

	size_t i = 0;
	const size_t end = source.length();
	string currentToken;

	enum
	{
		Token_None = 0,
		Token_Alpha = 1,
		Token_Numeric = 2,
	};
	int tokenType = Token_None;

	while (i < end)
	{
		const char c = source[i];
		const char next = (i + 1 < end ? source[i+1] : '\0');

		if (isspace(c))
		{
			// skip whitespace, end current token
			if (currentToken.length() != 0)
			{
				Result.push_back(currentToken);
				currentToken.clear();
				tokenType = Token_None;
			}
		}
		else if (isalpha(c))
		{
			// If building a numeric token, end it
			if (tokenType == Token_Numeric)
			{
				Result.push_back(currentToken);
				currentToken.clear();
			}

			currentToken.push_back(c);
			tokenType = Token_Alpha;
		}
		else if (isdigit(c) || c == '.')
		{
			// If building an alpha token, end it
			if (tokenType == Token_Alpha)
			{
				Result.push_back(currentToken);
				currentToken.clear();
			}

			currentToken.push_back(c);
			tokenType = Token_Numeric;
		}
		else if (c == '/')
		{
			if (next == '/')
			{
				// This is a comment, skip to the end of the line
				while (source[i] != '\n')
				{
					i ++;
				}
				// What about carriage returns? They will be skipped as whitespace
			}
		}
		else if (isprint(c))
		{
			// Some symbol, end current token
			if (currentToken.length() != 0)
			{
				Result.push_back(currentToken);
				currentToken.clear();
				tokenType = Token_None;
			}

			// Pass the symbol as a token itself
			Result.push_back(string(1, c));
		}
		else
		{
			// non-printing character, end current token
			if (currentToken.length() != 0)
			{
				Result.push_back(currentToken);
				currentToken.clear();
				tokenType = Token_None;
			}
		}

		i ++;
	}

	// Add the final token
	if (currentToken.length() > 0)
	{
		Result.push_back(currentToken);
	}

	return Result;
}
