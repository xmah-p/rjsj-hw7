
#include "./parser.h"

#include <iostream>
#include <stdexcept>
#include <unordered_map>

#include "./ai_derived.h"
#include "./rjsjai.h"

AI* Parser::doParse() {
    const char* MY_TOKEN{"32ed9a62-2519-43be-8420-c157a7b61fab"};
    int ai_type = 0;
    std::string prompt = "";
    std::string path = "";

    std::unordered_map<std::string, int> types{
        {"--chat", AI_TYPE_CHAT},
        {"--draw", AI_TYPE_DRAW},
        {"--math", AI_TYPE_WOLFRAM},
        {"--translate", AI_TYPE_TRANSLATE}};
    bool needPath = true;

    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
        auto token = *it;

        if (types.find(token) != types.end()) {
            if (ai_type != 0)
                throw std::runtime_error("Unexpected argument: " + token);
            ++it;
            if (it == tokens.end())
                throw std::runtime_error("Please enter prompt!");

            if (it->front() == '-')
                throw std::runtime_error("Invalid prompt: " + *it);
            prompt = *it;
        }

        else if (token == "--output" || token == "-o") {
            if (!needPath)
                throw std::runtime_error("Unexpected argument: " + token);
            ++it;
            if (it == tokens.end())
                throw std::runtime_error("Please specify a path!");
            if (it->front() == '-')
                throw std::runtime_error("Invalid path: " + *it);
            path = *it;
            needPath = false;
        }

        else
            throw std::runtime_error("Invalid argument: " + token);
    }
    if (ai_type == 0) throw std::runtime_error("Please specify an AI type!");
    if ((ai_type == AI_TYPE_DRAW || ai_type == AI_TYPE_WOLFRAM) && path == "")
        throw std::runtime_error("Please specify a path!");
    // if (needPath && path.substr(path.length() - 4) != ".png")
    //    throw std::runtime_error("Invalid path: " + path + ", must be a PNG
    //    file");

    switch (ai_type) {
        case AI_TYPE_CHAT:
            return new ChatAI(ai_create(MY_TOKEN), prompt, path);
            break;
        case AI_TYPE_DRAW:
            return new DrawAI(ai_create(MY_TOKEN), prompt, path);
            break;
        case AI_TYPE_WOLFRAM:
            return new MathAI(ai_create(MY_TOKEN), prompt, path);
            break;
        case AI_TYPE_TRANSLATE:
            return new TranslateAI(ai_create(MY_TOKEN), prompt);
            break;
        default:
            throw std::runtime_error("Fail to initialize AI!");
    }
}

AI* Parser::parse(int argc, char** argv) {
    try {
        return Parser(argc, argv).doParse();
    } catch (std::runtime_error& e) {
        std::cerr << e.what();
        return nullptr;
    }
}