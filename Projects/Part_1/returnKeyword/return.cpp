#include <iostream>

double calculateArea(double length);
double calculateVolume(double length);

int main(){
    double length;

    std::cout << "Enter the length of the square: ";
    std::cin >> length;

    double area = calculateArea(length);
    double volume = calculateVolume(length);

    std::cout << "Area: " << area << " cm^2" << '\n';

    std::cout << "Volume: " << volume << " cm^3" << '\n';

    return 0;
}

double calculateArea(double length){
    return length * length;
}

double calculateVolume(double length){
    return length * length * length;
}