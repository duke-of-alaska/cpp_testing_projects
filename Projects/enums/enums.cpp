#include <iostream>

using str = std::string;
constexpr auto& print = std::cout;

enum class Day{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main(){

    Day today = Day::Saturday;

    if(today == Day::Saturday || today == Day::Sunday){
        print << "It's the weekend!\n"; 
    }
    else{
        print << "It's the weekday!\n";
    }

}