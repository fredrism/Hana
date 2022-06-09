#include "Tokenizer.h"
#include <set>
#include <regex>

bool Tokenizer::is_operator_char(char c)
{
	std::set<char> operators =
	{
		'+', '-', '*', '/', '='
	};

	return operators.find(c) != operators.end();
}

bool is_keyword_string(std::string s)
{
	std::set<std::string> keywords =
	{
		"class",
		"const",
		"extern", "func",
		"public", "protected", "private"
	};

	return keywords.find(s) != keywords.end();
}

bool Tokenizer::is_whitespace(char ch)
{
	std::regex whitespace("\\s");
	return std::regex_match(std::string(1, ch), whitespace);
}

Token Tokenizer::read_literal_string(std::string::iterator& it)
{
	std::stringstream result;
	it++;

	while (it != m_string.end() && *it != '\"')
	{
		result << *it++;
	}
	it++;

	return { result.str(), TokenType::Literal };
}

Token Tokenizer::read_literal_char(std::string::iterator& it)
{
	it++;
	char ch = *it++;
	return { std::string(1, ch), TokenType::Literal};
}

Token Tokenizer::read_literal_number(std::string::iterator& it)
{
	std::stringstream result;

	while (it != m_string.end() && (std::isdigit(*it) || *it == '.'))
	{
		result << *it++;
	}

	return { result.str(), TokenType::Literal };
}

Token Tokenizer::read_indentifier(std::string::iterator& it)
{
	std::stringstream result;

	while (it != m_string.end() && (std::isalnum(*it)))
	{
		result << *it++;

		if (is_keyword_string(result.str()))
		{
			return { result.str(), TokenType::Keyword };
		}
	}

	return { result.str(), TokenType::Identifier };
}

Token Tokenizer::read_operator(std::string::iterator& it)
{
	std::stringstream result;

	while (it != m_string.end() && is_operator_char(*it))
	{
		result << *it++;
	}

	return { result.str(), TokenType::Operator };
}

Token Tokenizer::read_symbol(std::string::iterator& it)
{
	char ch = *it++;
	return { std::string(1, ch), TokenType::Symbol };
}

bool Tokenizer::GetToken(Token& token)
{
	while (m_iterator != m_string.end())
	{
		if (std::isalpha(*m_iterator)) { token = read_indentifier(m_iterator); return true; }
		else if (std::isdigit(*m_iterator)) {token = read_literal_number(m_iterator); return true; }
		else if (*m_iterator == '\"') {token = read_literal_string(m_iterator); return true; }
		else if (*m_iterator == '\'') {token = read_literal_char(m_iterator); return true; }
		else if (is_operator_char(*m_iterator)) {token = read_operator(m_iterator); return true; }
		else if (!is_whitespace(*m_iterator)) {token = read_symbol(m_iterator); return true; }

		m_iterator++;
	}

	token = { "\0", TokenType::None };
	return false;
}

Tokenizer::Tokenizer(std::string string)
{
	m_string = string;
	m_iterator = m_string.begin();
}
