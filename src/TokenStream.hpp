
#pragma once

#include <vector>
#include <string>


class TokenStream
{

public:

	TokenStream() = default;
	TokenStream(const std::vector<std::string> & tokens);
	void reset(const std::vector<std::string> & tokens);

	bool empty() const;
	std::string top() const;
	std::string pop();
	float pop_numeric();
	void require(std::string const & expectedToken);

protected:

	std::vector<std::string> Tokens;
	size_t i = 0;

};
