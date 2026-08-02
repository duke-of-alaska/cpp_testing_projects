#include <iostream>
#include <string>

using str = std::string;
constexpr auto& print = std::cout;
constexpr auto& pass = std::cin;

struct country{
    str name = "Temp";
    str capital = "Temp";
    bool isLandLocked = false; 

    void display() const{
        print << "Country: " << name << '\n';
        print << "Capital: " << capital << '\n';
        print << "Is it landlocked? " << (isLandLocked ? "Yes" : "No") << '\n';
    }
};



int main(){
    str name, capital;
    bool isLandLocked;

    print << "==== Welcome to the Country Information Program ====\n";
    print << "Enter the name of the country: ";
    std::getline(pass >> std::ws, name); // Read country name with whitespace handling

    print << "Enter the capital of the country: ";
    std::getline(pass >> std::ws, capital); // Read capital name

    print << "Is the country landlocked? (0 = No, 1 = Yes): ";
    pass >> isLandLocked; // Get landlocked status

    country c{name, capital, isLandLocked};
    print << "\n ==== Country Info ====\n";
    c.display();
    
}