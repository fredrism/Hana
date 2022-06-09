#pragma once
#include <string>
#include <vector>
#include <regex>
#include <sstream>

enum class TokenType
{
	Literal, Symbol, Operator, Identifier, Keyword, None
};

class Token
{
public:
	std::string value;
	TokenType type;
};

class Tokenizer
{
public:
	Tokenizer(std::string string);
	bool GetToken(Token& token);

private:
	std::string m_string;
	std::string::iterator m_iterator;

	bool is_operator_char(char c);
	bool is_whitespace(char ch);

	Token read_literal_string(std::string::iterator& it);
	Token read_literal_char(std::string::iterator& it);
	Token read_literal_number(std::string::iterator& it);
	Token read_indentifier(std::string::iterator& it);
	Token read_operator(std::string::iterator& it);
	Token read_symbol(std::string::iterator& it);
};

