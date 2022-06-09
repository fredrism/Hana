// Hana.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tokenizer.h"
#include <fstream>

int main()
{
    std::ifstream file("C:/Users/Fredrik/source/repos/Hana/Hana/demo.hna");
    std::stringstream ss;
    ss << file.rdbuf();

    Tokenizer tokenizer(ss.str());

    std::vector<Token> tokens;
    Token t;

    while (tokenizer.GetToken(t))
    {
        tokens.push_back(t);
        std::cout << t.value << std::endl;
    }

    int i = 0;
}
