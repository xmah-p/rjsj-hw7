#include "./parser.h"

#include <iostream>
#include <stdexcept>
#include <unordered_map>

#include "./rjsjai.h"

AI* Parser::doParse() {
    int ai_type = 0;
    std::string prompt = "";
    std::string path = "";

    std::unordered_map<std::string, int> types{{"--chat", AI_TYPE_CHAT},
                                               {"--draw", AI_TYPE_DRAW},
                                               {"--math", AI_TYPE_WOLFRAM}};
    bool needPath = true;

    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
        auto token = *it;

        if (types.find(token) != types.end()) {
            if (ai_type != 0)
                throw std::runtime_error("Invalid argument: " + token);
            if ((ai_type = types[token]) == AI_TYPE_CHAT) needPath = false;
            ++it;
            if (it->front() == '-')
                throw std::runtime_error("Invalid prompt: " + *it);
            prompt = *it;
        } 
        
        else if (token == "--output" || token == "-o") {
            if (!needPath) throw std::runtime_error("Unexpected argument: " + token);
            ++it;
            if (it->front() == '-')
                throw std::runtime_error("Invalid path: " + *it);
            path = *it;
        } 
        
        else
            throw std::runtime_error("Invalid argument: " + token);
    }

    return nullptr;
}

AI* Parser::parse(int argc, char** argv) {
    try {
        return Parser(argc, argv).doParse();
    } catch (std::runtime_error& e) {
        std::cerr << e.what();
    }
    return nullptr;
}