#include <iostream>
#include <string>

using str = std::string;

void Pizza();
void Pizza(str topping);

int main(){

    str topping;

    std::cout << "Topping: ";
    std::getline(std::cin >> std::ws, topping);
    
    Pizza();
    Pizza(topping);

    return 0;
}

void Pizza(){
    std::cout << "Pizza" << '\n';
}

void Pizza(str topping){
    std::cout << "Pizza with " << topping << '\n';
}