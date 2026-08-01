#include <iostream>
#include <string>

using str = std::string;
constexpr auto& print = std::cout;

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

    nation1.name = "Italy";
    nation1.capital = "Rome";
    nation1.isLandlocked = false;
    nation1.showNationInformation();
}