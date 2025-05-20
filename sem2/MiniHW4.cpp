#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<std::string> strings = { "Cat", "game", "hamburgers", "lambda" };

    auto count_chars = [](const std::string& str) { return str.size(); };

    for (const auto& str : strings) {
        std::cout << count_chars(str) << "\n";
    }
}