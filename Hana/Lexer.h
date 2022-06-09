#pragma once
#include "Tokenizer.h"
#include <memory>
#include <unordered_map>

enum AccessLevel
{
	Public, Protected, Private
};

class Field
{
public:
	std::string name;
	AccessLevel access;
	std::shared_ptr<Object> type;
};

class Func
{
public:
	std::string name;
	AccessLevel access;
	std::shared_ptr<ASTNode> ast;
};

class Object
{
public:
	std::unordered_map<std::string, Field> variables;
	std::unordered_map<std::string, Func> methods;
};

class ASTNode
{

};

class Lexer
{
public:
	Lexer(std::shared_ptr<Tokenizer> tokenizer);
	~Lexer();

	void ParseTokens();

private:
	std::shared_ptr<Tokenizer> m_tokenizer;
	std::unordered_map<std::string, std::shared_ptr<Object>> m_objects;
};

