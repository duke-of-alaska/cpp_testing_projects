#include <iostream>
#include <string>

constexpr auto& print = std::cout;

class Stove{
    private:
        int temperature = 0;
    public:
        int showTemperature()const {
            print << "Temp: " << temperature << "\n";
            return temperature;
        }

        void changeTemperature(int temperature){
            if(temperature < 0){
                this->temperature = 0;
            }
            else if(temperature > 10){
                this->temperature = 10;
            }
            else{
                this->temperature = temperature;
            }
        }
};

int main(){
    int temp;

    Stove stove;
    print << "Enter temperature of the stove: ";
    std::cin >> temp;

    stove.changeTemperature(temp); // Can only range from 0-10
    stove.showTemperature();
}