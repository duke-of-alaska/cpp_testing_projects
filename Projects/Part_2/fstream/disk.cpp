#include <iostream>
#include <string>
#include <fstream>

using str = std::string;
static auto& print = std::cout;

int main() {
    print << "Enter a string to save:\n";
    str userInput{};
    std::getline(std::cin >> std::ws, userInput);

    std::ofstream file("userinput.txt", std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Unable to open file!\n";
        return 1;
    }

    file << userInput << '\n';
    std::cout << "Success!\n";
    return 0;
}