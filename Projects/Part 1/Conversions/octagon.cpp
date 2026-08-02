#include <iostream>
#include <cmath>

double calculateArea(double length);
double calculateVolume(double length, double height);

int main(){
    double length = 2.0;
    double height = 2.0;

    double result = calculateArea(length);
    std::cout << result << '\n';

    double result2 = calculateVolume(length, height);
    std::cout << result2 << '\n';

}

double calculateArea(double length){
    return 2 * (1 + std::sqrt(2)) * (length * length);
}

double calculateVolume(double length, double height){
    return calculateArea(length) * height;
}