#include "Lexer.h"

void Lexer::ParseTokens()
{
	Token token;
	while (m_tokenizer->GetToken(token))
	{
		if(token.type == TokenType::Keyword)
	}
}
