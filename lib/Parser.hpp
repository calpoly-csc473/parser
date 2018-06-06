
// Copyright (C) 2018 Ian Dunn
// For conditions of distribution and use, see the LICENSE file


#pragma once

#include <vector>
#include <string>

#include "TokenStream.hpp"
#include "Objects.hpp"


namespace parser
{

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

}
