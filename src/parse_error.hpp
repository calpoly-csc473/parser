
#pragma once

#include <stdexcept>


class parse_error : public std::domain_error
{

public:

	parse_error() = default;
	parse_error(const std::string & what_arg) : std::domain_error(what_arg) {}
	parse_error(const char * what_arg) : std::domain_error(what_arg) {}

};
