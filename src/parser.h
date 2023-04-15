#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>

#include "./ai.h"

class Parser {
    std::vector<std::string> tokens;
    Parser(int argc, char** argv) : tokens(argv + 1, argv + argc){};
    AI* doParse();

public:
    static AI* parse(int argc, char** argv);
};

#endif
