#include <iostream>

static auto& devv = std::cout;

int main() {
    devv << "Hello!" << '\n';
}