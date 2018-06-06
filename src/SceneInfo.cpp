
// Copyright (C) 2018 Ian Dunn
// For conditions of distribution and use, see the LICENSE file


#include <Tokenizer.hpp>
#include <Parser.hpp>

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
using namespace parser;


void SceneInfo(const Parser & p);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cerr << "usage: ./parser <filename>" << endl;
		return 1;
	}

	ifstream File;
	File.open(argv[1]);

	if (! File.is_open())
	{
		cerr << "Failed to open file '" << argv[1] << "'\n" << endl;
		return 2;
	}

	string Contents{istreambuf_iterator<char>(File), istreambuf_iterator<char>()}; // inefficient

	Parser p;

	try
	{
		TokenStream ts = Tokenizer::Tokenize(Contents);
		p.Parse(ts);
	}
	catch (const std::exception & e)
	{
		cerr << "exception: " << e.what() << endl;
	}

	SceneInfo(p);

	return 0;
}

ostream & operator << (ostream & stream, const vec3 & vec)
{
	return stream << vec.x << " " << vec.y << " " << vec.z;
}

ostream & operator << (ostream & stream, const vec4 & vec)
{
	return stream << vec.x << " " << vec.y << " " << vec.z << " " << vec.w;
}

void SceneInfo(const Parser & p)
{
	cout << std::setiosflags(std::ios::fixed);
	cout << std::setprecision(4);

	cout << "Camera:" << endl;
	cout << "- Location: {" << p.camera.location << "}" << endl;
	cout << "- Up: {" << p.camera.up << "}" << endl;
	cout << "- Right: {" << p.camera.right << "}" << endl;
	cout << "- Look at: {" << p.camera.look_at << "}" << endl;
	cout << endl;
	cout << "---" << endl;
	cout << endl;

	cout << p.lights.size() << " light(s)" << endl;
	for (size_t i = 0; i < p.lights.size(); ++ i)
	{
		cout << endl;
		cout << "Light[" << i << "]:" << endl;
		cout << "- Location: {" << p.lights[i].position << "}" << endl;
		cout << "- Color: {" <<
			p.lights[i].color.x << " " <<
			p.lights[i].color.y << " " <<
			p.lights[i].color.z << "}" << endl;
	}

	cout << endl;
	cout << "---" << endl;
	cout << endl;

	cout << p.objects.size() << " object(s)" << endl;
	for (size_t i = 0; i < p.objects.size(); ++ i)
	{
		const Object & o = p.objects[i];

		cout << endl;
		cout << "Object[" << i << "]:" << endl;

		switch (o.type)
		{
		case Object::Type::Sphere:
			cout << "- Type: Sphere" << endl;
			cout << "- Center: {" << o.v1 << "}" << endl;
			cout << "- Radius: " << o.s1 << endl;
			break;

		case Object::Type::Plane:
			cout << "- Type: Plane" << endl;
			cout << "- Normal: {" << o.v1 << "}" << endl;
			cout << "- Distance: " << o.s1 << endl;
			break;

		case Object::Type::Triangle:
			cout << "- Type: Triangle" << endl;
			cout << "- Vertices[0]: {" << o.v1 << "}" << endl;
			cout << "- Vertices[1]: {" << o.v2 << "}" << endl;
			cout << "- Vertices[2]: {" << o.v3 << "}" << endl;
			break;

		case Object::Type::Box:
			cout << "- Type: Box" << endl;
			cout << "- Min: {" << o.v1 << "}" << endl;
			cout << "- Max: {" << o.v2 << "}" << endl;
			break;

		case Object::Type::Cone:
			cout << "- Type: Cone" << endl;
			cout << "- Center 1: {" << o.v1 << "}" << endl;
			cout << "- Radius 1: " << o.s1 << endl;
			cout << "- Center 2: {" << o.v2 << "}" << endl;
			cout << "- Radius 2: " << o.s2 << endl;
			break;
		}

		// if (o.attributes.pigment.w)
		// 	cout << "- Color: {" << o.attributes.pigment << "}" << endl;
		// else
			cout << "- Color: {" <<
				o.attributes.pigment.x << " " <<
				o.attributes.pigment.y << " " <<
				o.attributes.pigment.z << "}" << endl;
		cout << "- Material:" << endl;
		cout << "  - Ambient: " << o.attributes.finish.ambient << endl;
		cout << "  - Diffuse: " << o.attributes.finish.diffuse << endl;
		// if (o.attributes.finish.specular)
		// 	cout << "  - Specular: " << o.attributes.finish.diffuse << endl;
		// if (o.attributes.finish.reflection)
		// 	cout << "  - Reflection: " << o.attributes.finish.diffuse << endl;
	}
}
