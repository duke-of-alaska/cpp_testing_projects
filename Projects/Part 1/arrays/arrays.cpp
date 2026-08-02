#include <iostream>
#include <vector>
#include <string>

using str = std::string;

int main(){
    std::vector<str> countries;
    str countryAdd;
    int choice = 0;

    do{std::cout << "==== Country Adder ==== " << '\n';
    std::cout << "1. Add country" << '\n';
    std::cout << "2. List" << '\n';
    std::cout << "3. Quit" << '\n';
    std::cout << "Choice: ";
    std::cin >> choice;

    switch(choice){
        case 1:
            std::cout << "What country would you like to add? ";
            std::getline(std::cin >> std::ws, countryAdd);
            countries.push_back(countryAdd);
            break;
        case 2:
            std::cout << '\n' << "==== Country List ==== " << '\n';
            for (const str& C : countries){
                std::cout << "- " << C << '\n';
            }
            std::cout << "==== ============ ====\n\n";
        case 3:
            break;
        default:
            std::cout << "Invalid option!";
            break;
    }
    }while (choice != 3);

    

    return 0;
}