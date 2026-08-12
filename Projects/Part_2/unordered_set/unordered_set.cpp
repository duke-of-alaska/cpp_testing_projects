#include <iostream>
#include <print>
#include <unordered_set>

using std::unordered_set;

int main() {
    unordered_set<int> s;
    int choice{};

    do{
        std::println("==== Welcome! ====\n"
                  "1. Add number\n"
                  "2. List numbers\n"
                  "3. Quit");

        std::println("Select choice:");

        ;
        if (!(std::cin >> choice)) {
            std::cerr << "Not a valid choice!";
            return 1;
        }

        switch (choice) {
            case 1: {
                std::println("What number do you want to add?");
                int x{};
                if (!(std::cin >> x)) {
                    std::cerr << "Not an integer!\n";
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

            default:
                std::cerr << "Not a valid choice!\n";
                break;
        }
    }while(choice != 3);

    return 0;
}