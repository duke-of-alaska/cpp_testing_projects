#include <iostream>
#include <print>
#include <unordered_set>
#include <algorithm>
#include <cctype>
#include <string>

using std::unordered_set;
using str = std::string;
str lowercaseAlgo(str& input);

int main() {
    unordered_set<int> s;
    int choice{};

    do{
        std::println("\n==== welcome! ====\n"
                  "1. add number\n"
                  "2. list numbers\n"
                  "3. quit\n"
                  "4. check existence of number\n"
                  "5. remove value\n"
                  "6. nuke everything");

        std::println("select choice:");

        ;
        if (!(std::cin >> choice)) {
            std::cerr << "not a valid choice!";
            return 1;
        }

        switch (choice) {
            case 1: {
                std::println("what number do you want to add?");
                int x{};
                if (!(std::cin >> x)) {
                    std::cerr << "not an integer!\n";
                    return 1;
                }
                s.insert(x);
                break;
            }

            case 2:
                for (int y : s) {
                    std::print("{}\n", y);
                }
                break;

            case 3:
                break;

            case 4: {
                std::println("what number to find?");
                int toFind{};

                if (!(std::cin >> toFind)) {
                    std::cerr << "not a valid number!\n";
                    return 1;
                }

                if (s.contains(toFind)) {
                    std::println("found!");
                }
                else {
                    std::println("not found!");
                }

                break;
            }

            case 5: {
                std::println("what number to remove?");
                int toRemove{};
                if (!(std::cin >> toRemove)) {
                    std::cerr << "not a valid number!\n";
                    return 1;
                }

                if (s.erase(toRemove)) {
                    std::println("removed {}", toRemove);
                }
                else {
                    std::println("{} was not found", toRemove);
                }

                break;
            }

            case 6: {
                std::println("are you sure you want to nuke everything? (y/n)");
                str confirmation{};
                std::getline(std::cin >> std::ws, confirmation);

                auto toLowercase = [](str s) {
                    for (char &c : s) {
                        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
                    }
                    return s;
                };

                str lowercased = toLowercase(confirmation);

                if (lowercased == "y") {
                    s.clear();
                    std::println("entire set nuked");
                }
                else if (lowercased == "n") {
                    std::println("set not nuked");
                }
                else {
                    std::println("invalid choice. return to main menu");
                }

                break;
            }


            default:
                std::cerr << "not a valid choice!\n";
                break;
        }
    }while(choice != 3);

    return 0;
}

