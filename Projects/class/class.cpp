#include <iostream>
#include <string>

// Type alias
using str = std::string;

// Safe, standard stream references
auto& print = std::cout;
auto& pass = std::cin;

class Nation {
public:
    // Member initializers
    str name{"Unknown"};
    str capital{"Unknown"};
    bool isLandlocked{false};

    // const member function guaranteeing no mutations to 'this'
    void showNationInformation() const {
        print << "\n--- Nation Info ---\n";
        print << "Nation: " << name << "\n";
        print << "Capital: " << capital << "\n";
        print << "Is Landlocked: " << (isLandlocked ? "Yes" : "No") << "\n";
    }
};

int main() {
    Nation nation1;

    print << "Enter the name of the nation: ";
    std::getline(pass, nation1.name);

    print << "Enter the capital of the nation: ";
    std::getline(pass, nation1.capital);

    print << "Is the nation landlocked? (1 for Yes, 0 for No): ";
    pass >> nation1.isLandlocked;

    nation1.showNationInformation();
}