
# CSC 473 Pov-Ray Parser Implementation

Sample parser for CSC 473 subset of Pov-Ray file format.

You can feel free to use this in your projects.
However, bare in mind that the cost of integration may be higher than the maintenance cost of your current parser,
even if your parser has bugs.


## How To Use

The easiest option is probably to copy the source files in [`lib/`](lib/) into your project,
then take a look at [`src/Main.cpp`](src/Main.cpp) to see how to parse a file and access the relevant data.
I would recommend using the structs defined in [`lib/Parse.hpp`](lib/Parser.hpp) to initialize your own Object classes.

Alternatively, you could add some code in [`lib/Parse.cpp`](lib/Parser.cpp) to create instances of your Object class while parsing.

Regardless of what you do, it would probably be a good idea to remove the `vec3` and `vec4` classes and just include `glm.hpp`.
I opted to use a simple struct just to avoid any dependencies.


## Documentation

The parsing pipeline consists of three major classes.

- The **Tokenizer** takes the contents of a file and converts it to an array of tokens.
- The **TokenStream** takes this array of tokens and provides a basic iterator with some common operations.
- The **Parser** uses the TokenStream to create camera, light, and object structs containing all relevant scene information.

Some additional details can be found in most `.hpp` files.


## File Format

The following elements are supported:

- // comments
- camera
- light_source
- sphere
- plane
- triangle
- box
- cone
- pigment
  - color
    - rgb
    - rgbf
- finish
  - ambient
  - diffuse
  - specular
  - roughness
  - reflection
  - refraction
  - ior
- translate, scale, rotate

## FAQ

**Q:** Why did you put copyright notices and a license on this software?
Don't you want use to be free to use this code in our projects?

**A:** Yes I do - I put a permissive open-source license on this code to
*increase* your rights to use this software, not *decrease* them.
Any time you write software, you automatically own the copyright on that software - no registration is necessary.
So if I distributed this code without any notices or licenses attached,
I would still own the copyright, and in using the code you would technically be commiting copyright infringement.
For the purposes of this class you are very likely protected by **Fair Use**,
but if you decided to sell your raytracer commerically at some later date,
that would definitely be copyright infringement.
Obviously, I am not likely to sue any of my former students...

However, if the software is licensed to you under a permissive open-source license,
you are legally free to use the software in whatever capacity you desire (including commercially).

For more information, give this a read: [https://opensource.org/faq](https://opensource.org/faq)

---

**Q:** This is really inefficient!

**A:** Yes it is. Some minor changes could be made to make e.g. file reading and tokenization much faster.
The goal of this project is simplicity, not performance.
And on a relatively slow CPU I found that it takes less than 2 seconds to parse every single `.pov` file from this class at once,
so it's probably fast enough as is.
