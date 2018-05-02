
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
			camera = ParseCamera(tokens);
		}
		else if (token == "light_source")
		{
			lights.push_back(ParseLightSource(tokens));
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
			throw parse_error("unexpected top-level object", token);
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
	vec4 color = { 0 };

	tokens.require("color");
	string type = tokens.pop();

	if (type == "rgb")
	{
		vec3 v = ParseVector3(tokens);
		color.x = v.x;
		color.y = v.y;
		color.z = v.z;
	}
	else if (type == "rgbf")
	{
		color = ParseVector4(tokens);
	}
	else
	{
		throw parse_error("unexpected color type", type);
	}

	return color;
}

vec4 Parser::ParsePigment(TokenStream & tokens)
{
}

Material Parser::ParseMaterial(TokenStream & tokens)
{
}


Camera Parser::ParseCamera(TokenStream & tokens)
{
	Camera c;

	tokens.require("{");

	while (! tokens.empty())
	{
		string token = tokens.pop();

		if (token == "location")
			c.location = ParseVector3(tokens);
		else if (token == "look_at")
			c.look_at = ParseVector3(tokens);
		else if (token == "up")
			c.up = ParseVector3(tokens);
		else if (token == "right")
			c.right = ParseVector3(tokens);
		else if (token == "}")
			break;
		else
			throw parse_error("unexpected camera attribute", token);
	}

	return c;
}

Light Parser::ParseLightSource(TokenStream & tokens)
{
	Light l;

	tokens.require("{");
	l.position = ParseVector3(tokens);
	l.color = ParseColor(tokens);
	tokens.require("}");

	return l;
}


Attributes Parser::ParseAttributes(TokenStream & tokens)
{
	Attributes a;

	return a;
}


Sphere Parser::ParseSphere(TokenStream & tokens)
{
	Sphere s;

	return s;
}

Plane Parser::ParsePlane(TokenStream & tokens)
{
	Plane p;

	return p;
}

Triangle Parser::ParseTriangle(TokenStream & tokens)
{
	Triangle t;

	return t;
}

Box Parser::ParseBox(TokenStream & tokens)
{
	Box b;

	return b;
}

Cone Parser::ParseCone(TokenStream & tokens)
{
	Cone c;

	return c;
}
