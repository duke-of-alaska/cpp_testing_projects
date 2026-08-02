#include <iostream>
#include <string>

using str = std::string;
constexpr auto& print = std::cout;
constexpr auto& pass = std::cin;

class Nation{
    public:
        str name = "Temp";
        str capital = "Temp";
        bool isLandlocked = false;

        void showNationInformation() const{
            print << "Nation: " << name << "\n";
            print << "Capital: " << capital << "\n";
            print << "Is Landlocked: " << (isLandlocked ? "Yes" : "No") << "\n";
        }
};

int main(){
    Nation nation1;
    str nationName = "Temp";
    str nationCapital = "Temp";
    bool isLandlocked = false;

    print << "Enter the name of the nation: ";
    std::getline(pass >> std::ws, nationName);
    nation1.name = nationName;

    print << "Enter the capital of the nation: ";
    std::getline(pass >> std::ws, nationCapital);
    nation1.capital = nationCapital;

    print << "Is the nation landlocked? (1 for Yes, 0 for No): ";
    pass >> isLandlocked;
    nation1.isLandlocked = isLandlocked;

    nation1.showNationInformation();
}