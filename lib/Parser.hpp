
// Copyright (C) 2018 Ian Dunn
// For conditions of distribution and use, see the LICENSE file


#pragma once

#include <vector>
#include <string>

#include "TokenStream.hpp"


struct vec3
{
	float x = 0, y = 0, z = 0;
};

struct vec4
{
	float x = 0, y = 0, z = 0, w = 0;
};

struct Finish
{
	float ambient = 0;
	float diffuse = 0;
	float specular = 0;

	float roughness = 1;
	float reflection = 0;
	float ior = 1;
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
	float s1 = 0, s2 = 0;
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


/// Takes a TokenStream and parses the entire file, filling the
/// camera, lights, and objects fields with the scene information.
///
/// Any malformed or unexpected contents in the .pov file is likely
/// to throw an exception.
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
