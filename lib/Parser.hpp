
#pragma once

#include <vector>
#include <string>

#include "TokenStream.hpp"

struct vec3
{
	float x, y, z;
};

struct vec4
{
	float x, y, z, w;
};

struct Finish
{
	float ambient;
	float diffuse;
	float specular;

	float roughness;
	float reflection;
	float ior;
};

struct Transform
{
	enum class Type
	{
		Translate,
		Scale,
		Rotate
	};

	vec3 quantity;
	Type type;
};

struct Attributes
{
	vec4 pigment;
	Finish finish;
	std::vector<Transform> transforms;
};

struct Object
{
	enum class Type
	{
		Sphere,
		Plane,
		Triangle,
		Box,
		Cone
	};

	Type type;
	vec3 v1, v2, v3;
	float s1, s2;
	Attributes attributes;
};

struct Camera
{
	vec3 up, right, look_at, location;
};

struct Light
{
	vec3 position;
	vec4 color;
};


class Parser
{

public:

	void Parse(TokenStream & tokens);

	Camera camera;
	std::vector<Light> lights;
	std::vector<Object> objects;

	static vec3 ParseVector3(TokenStream & tokens);
	static vec4 ParseVector4(TokenStream & tokens);
	static vec4 ParseColor(TokenStream & tokens);
	static vec4 ParsePigment(TokenStream & tokens);
	static Finish ParseFinish(TokenStream & tokens);
	static Attributes ParseAttributes(TokenStream & tokens);

	static Camera ParseCamera(TokenStream & tokens);
	static Light ParseLightSource(TokenStream & tokens);

	static Object ParseSphere(TokenStream & tokens);
	static Object ParsePlane(TokenStream & tokens);
	static Object ParseTriangle(TokenStream & tokens);
	static Object ParseBox(TokenStream & tokens);
	static Object ParseCone(TokenStream & tokens);

};
