#ifndef _CONSOLE_PARSER_HPP_
#define _CONSOLE_PARSER_HPP_

#include <iostream>
#include <CommandLineParser.hpp>

using namespace std;
enum ETokenType {
	None = 0,
	Command,
	Option,
	ArgString,
	ArgInteger
};

struct Token {
	string text;
	int type;
};


class ConsoleParser {
public:
	
private:
};



#endif



