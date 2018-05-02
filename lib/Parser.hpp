
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

struct Material
{
	vec4 color;

	float ambient;
	float diffuse;
	float specular;

	float roughness;
	float reflection;
	float ior;
};

struct Transform
{
	vec3 quantity;

	enum class Type
	{
		Translate,
		Scale,
		Rotation
	};
	Type type;
};

struct Attributes
{
	Material material;
	std::vector<Transform> transforms;
};

struct Camera
{
	vec3 up, right, look_at, location;
};

struct Light
{
	vec3 color;
	vec3 position;
};

struct Sphere
{
	vec3 center;
	float radius;
	Attributes attributes;
};

struct Plane
{
	vec3 normal;
	float distance;
	Attributes attributes;
};

struct Triangle
{
	vec3 a, b, c;
	Attributes attributes;
};

struct Box
{
	vec3 min, max;
	Attributes attributes;
};

struct Cone
{
	vec3 min, max;
	float r1, r2;
	Attributes attributes;
};


class Parser
{

public:

	void Parse(TokenStream & tokens);

	Camera camera;
	std::vector<Light> lights;

	static vec3 ParseVector3(TokenStream & tokens);
	static vec4 ParseVector4(TokenStream & tokens);
	static vec4 ParseColor(TokenStream & tokens);
	static vec4 ParsePigment(TokenStream & tokens);
	static Material ParseMaterial(TokenStream & tokens);

	static Camera ParseCamera(TokenStream & tokens);
	static Light ParseLightSource(TokenStream & tokens);

	static Attributes ParseAttributes(TokenStream & tokens);

	static Sphere ParseSphere(TokenStream & tokens);
	static Plane ParsePlane(TokenStream & tokens);
	static Triangle ParseTriangle(TokenStream & tokens);
	static Box ParseBox(TokenStream & tokens);
	static Cone ParseCone(TokenStream & tokens);

};
