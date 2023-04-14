#include "./ai_derived.h"

#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <ranges>
#include <stdexcept>
#include <string>

#include "rjsjai.h"


ChatAI::~ChatAI() { ai_free(bot); }

void ChatAI::sendRequest() {
    try {
        ai_send(bot, AI_TYPE_CHAT, prompt.c_str());
        int code = ai_status(bot);
        if (code != 0)
            throw std::runtime_error(
                "Error occurred when sending requests! Error code: " +
                std::to_string(code));

    } catch (std::runtime_error& e) {
        std::cerr << e.what();
    }
}

void ChatAI::showResponse() {
    std::ostream_iterator<char> os_it(std::cout);
    char* dest;
    int len = ai_result(bot, dest);
    std::copy(dest, dest + len, os_it);
}

void DrawAI::showResponse() {
    std::ofstream out_file(path, std::ios::out);
    std::ostream_iterator<char> os_it(out_file);
    
    char* dest;
    int len = ai_result(bot, dest);
    std::copy(dest, dest + len, os_it);
}

void MathAI::showResponse() {
    std::ofstream out_file(path, std::ios::out);
    std::ostream_iterator<char> os_it(out_file);

    char* dest;
    int len = ai_result(bot, dest);
    std::copy(dest, dest + len, os_it);
}

void DrawAI::sendRequest() {
    try {
        ai_send(bot, AI_TYPE_DRAW, prompt.c_str());
        int code = ai_status(bot);
        if (code != 0)
            throw std::runtime_error(
                "Error occurred when sending requests! Error code: " +
                std::to_string(code));

    } catch (std::runtime_error& e) {
        std::cerr << e.what();
    }
}

void MathAI::sendRequest() {
    try {
        ai_send(bot, AI_TYPE_WOLFRAM, prompt.c_str());
        int code = ai_status(bot);
        if (code != 0)
            throw std::runtime_error(
                "Error occurred when sending requests! Error code: " +
                std::to_string(code));

    } catch (std::runtime_error& e) {
        std::cerr << e.what();
    }
}

DrawAI::~DrawAI() { ai_free(bot); }

MathAI::~MathAI() { ai_free(bot); }
