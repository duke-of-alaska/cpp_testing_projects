#include <iostream>
#include <unordered_map>
#include <string>
#include <limits>

using str = std::string;
using std::unordered_map;
static auto& print = std::cout;

int main() {
    int choice{};
    str name;
    str job;

    unordered_map<str, str> test;

    do {
        print << "\n==== Welcome to the name and job program (using unordered_map)! ====\n";
        print << "Select option:\n "
                 "1. Add name and job\n "
                 "2. List all names with job\n"
                 "3. Quit\n";
        print << "Select choice:\n";

        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            print << "Invalid input.\n";
            continue;
        }

        switch (choice) {
            case 1:
                print << "Enter name:\n";
                std::getline(std::cin >> std::ws, name);

                print << "Enter job / profession:\n";
                std::getline(std::cin >> std::ws, job);

                test[name] = job;
                break;

            case 2:
                for (const auto& [name, job] : test) {
                    print << name << " -> " << job << '\n';
                }
                break;

            case 3:
                break;

            default:
                print << "No such option!\n";
        }
    }while (choice != 3);

    return 0;
}