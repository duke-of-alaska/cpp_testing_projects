#include <iostream>
#include <string>

using str_t = std::string;

str_t concatString(str_t string_a, str_t string_b);

int main(){
    str_t string_a; // First name

    std::cout << "Enter your first name: ";
    std::getline(std::cin >> std::ws, string_a);

    str_t string_b; // Last name

    std::cout << "Enter your last name: ";
    std::getline(std::cin >> std::ws, string_b);

    str_t combined_string = concatString(string_a, string_b); // Combine

    std::cout << "Hello, " << combined_string << "!" << '\n'; // Output
    return 0;
}

str_t concatString(str_t string_a, str_t string_b){
    return string_a + " " + string_b;
}