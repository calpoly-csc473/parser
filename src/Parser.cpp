
#include "Parser.hpp"
#include "parse_error.hpp"
#include <sstream>

using namespace std;


void Parser::Parse(TokenStream & tokens)
{
	while (! tokens.empty())
	{
		const string token = tokens.pop();

		if (token == "camera")
		{
			ParseCamera(tokens);
		}
		else if (token == "light_source")
		{
			ParseLightSource(tokens);
		}
		else if (token == "sphere")
		{
			ParseSphere(tokens);
		}
		else if (token == "triangle")
		{
			ParseTriangle(tokens);
		}
		else if (token == "box")
		{
			ParseBox(tokens);
		}
		else if (token == "cone")
		{
			ParseCone(tokens);
		}
		else if (token == "plane")
		{
			ParsePlane(tokens);
		}
		else
		{
			stringstream s;
			s << "unexpected top-level object '" << token;
			throw parse_error(s.str());
		}
	}
}

vec3 Parser::ParseVector3(TokenStream & tokens)
{
	vec3 v;
	tokens.require("<");
	v.x = tokens.pop_numeric();
	tokens.require(",");
	v.y = tokens.pop_numeric();
	tokens.require(",");
	v.z = tokens.pop_numeric();
	tokens.require(">");
	return v;
}

vec4 Parser::ParseVector4(TokenStream & tokens)
{
	vec4 v;
	tokens.require("<");
	v.x = tokens.pop_numeric();
	tokens.require(",");
	v.y = tokens.pop_numeric();
	tokens.require(",");
	v.z = tokens.pop_numeric();
	tokens.require(",");
	v.w = tokens.pop_numeric();
	tokens.require(">");
	return v;
}


vec4 Parser::ParseColor(TokenStream & tokens)
{
}

vec4 Parser::ParsePigment(TokenStream & tokens)
{
}

Material Parser::ParseMaterial(TokenStream & tokens)
{
}


Camera Parser::ParseCamera(TokenStream & tokens)
{
}

Light Parser::ParseLightSource(TokenStream & tokens)
{
}


Attributes Parser::ParseAttributes(TokenStream & tokens)
{
}


Sphere Parser::ParseSphere(TokenStream & tokens)
{
}

Plane Parser::ParsePlane(TokenStream & tokens)
{
}

Triangle Parser::ParseTriangle(TokenStream & tokens)
{
}

Box Parser::ParseBox(TokenStream & tokens)
{
}

Cone Parser::ParseCone(TokenStream & tokens)
{
}
