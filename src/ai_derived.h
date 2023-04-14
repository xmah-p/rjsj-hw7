#include <memory>
#include <string>

#include "ai.h"
#include "rjsjai.h"

class ChatAI : public AI {
private:
    RJSJAI* bot;
    std::string prompt;

public:
    ChatAI(RJSJAI* bot, std::string prompt) : bot{bot}, prompt(prompt) {}

    void sendRequest() final;
    void showResponse() final;
    ~ChatAI();
};

class DrawAI : public AI {
private:
    RJSJAI* bot;
    std::string prompt;
    std::string path;

public:
    DrawAI(RJSJAI* bot, std::string prompt, std::string path)
        : bot{bot}, prompt(prompt), path(path) {}

    void sendRequest() final;
    void showResponse() final;
    ~DrawAI();
};

class MathAI : public AI {
private:
    RJSJAI* bot;
    std::string prompt;
    std::string path;

public:
    MathAI(RJSJAI* bot, std::string prompt, std::string path)
        : bot{bot}, prompt(prompt), path(path) {}

    void sendRequest() final;
    void showResponse() final;
    ~MathAI();
};