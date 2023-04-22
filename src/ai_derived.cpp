#include "./ai_derived.h"

#include <algorithm>
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
    char* dest{nullptr};
    int len = ai_result(bot, dest);
    dest = new char[len + 1];
    ai_result(bot, dest);
    if (path == "")
        std::copy(dest, dest + len + 1, std::ostream_iterator<char>(std::cout));
    else {
        std::ofstream out_file(path, std::ios::out | std::ios::binary);
        std::copy(dest, dest + len + 1, std::ostream_iterator<char>(out_file));
    }
    delete[] dest;
}

DrawAI::~DrawAI() { ai_free(bot); }

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

void DrawAI::showResponse() {
    std::ofstream out_file(path, std::ios::out | std::ios::binary);
    std::ostream_iterator<char> os_it(out_file);
    char* dest{nullptr};
    int len = ai_result(bot, dest);
    dest = new char[len + 1];
    ai_result(bot, dest);
    std::copy(dest, dest + len + 1, os_it);
    delete[] dest;
}

MathAI::~MathAI() { ai_free(bot); }

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

void MathAI::showResponse() {
    std::ofstream out_file(path, std::ios::out | std::ios::binary);
    std::ostream_iterator<char> os_it(out_file);
    char* dest{nullptr};
    int len = ai_result(bot, dest);
    dest = new char[len + 1];
    ai_result(bot, dest);
    std::copy(dest, dest + len + 1, os_it);
    delete[] dest;
}

TranslateAI::~TranslateAI() { ai_free(bot); }

void TranslateAI::sendRequest() {
    try {
        ai_send(bot, AI_TYPE_TRANSLATE, prompt.c_str());
        int code = ai_status(bot);
        if (code != 0)
            throw std::runtime_error(
                "Error occurred when sending requests! Error code: " +
                std::to_string(code));

    } catch (std::runtime_error& e) {
        std::cerr << e.what();
    }
}

void TranslateAI::showResponse() {
    std::ostream_iterator<char> os_it(std::cout);
    char* dest{nullptr};
    int len = ai_result(bot, dest);
    dest = new char[len + 1];
    ai_result(bot, dest);
    std::copy(dest, dest + len + 1, os_it);
    delete[] dest;
}