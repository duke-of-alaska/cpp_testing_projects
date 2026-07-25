#include <iostream>

using str = std::string;

int main(){
    str countries[3];

    countries[0] = "Indonesia";
    countries[1] = "China";
    countries[2] = "Croatia";

    std::cout << countries[0] << '\n';
    return 0;
}