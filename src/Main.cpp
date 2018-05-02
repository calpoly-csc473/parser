
#include <Tokenizer.hpp>
#include <Parser.hpp>

#include <iostream>
#include <fstream>
using namespace std;


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

	TokenStream ts = Tokenizer::Tokenize(Contents);
	Parser p;
	p.Parse(ts);

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
		cout << "- Color: {" << p.lights[i].color << "}" << endl;
	}

	cout << endl;
	cout << "---" << endl;
	cout << endl;

	// cout << Scene->GetObjects().size() << " object(s)" << endl;
	// for (size_t i = 0; i < Scene->GetObjects().size(); ++ i)
	// {
	// 	cout << endl;
	// 	cout << "Object[" << i << "]:" << endl;
	// 	cout << "- Type: " << Scene->GetObjects()[i]->GetObjectType() << endl;
	// 	cout << Scene->GetObjects()[i]->GetObjectInfo();
	// }
}
