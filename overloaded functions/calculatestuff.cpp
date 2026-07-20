#include <iostream>

const double PI = 3.1415;

double calculateArea(double side);
double calculateArea(double length, double width);
double calculateArea(double radius, char type);

int main(){

    double square_side;

    std::cout << "Side of square in cm? ";
    std::cin >> square_side; 

    double square = calculateArea(square_side);

    std::cout << square << "cm^2" << '\n';

    double rectangle_length;
    double rectangle_width;
    
    std::cout << "Length of rectangle in cm? ";
    std::cin >> rectangle_length;

    std::cout << "Width of rectangle in cm? ";
    std::cin >> rectangle_width;

    double rectangle = calculateArea(rectangle_length, rectangle_width);

    std::cout << rectangle << "cm^2" << '\n';

    double circle_radius;

    std::cout << "Radius of circle in cm? ";
    std::cin >> circle_radius;

    double circle = calculateArea(circle_radius, 'c');

    std::cout << circle << "cm^2" <<  '\n';
    

    return 0;
}

double calculateArea(double side){
    return side * side;
}

double calculateArea(double length, double width){
    return length * width;
}

double calculateArea(double radius, char type){
    if(type == 'c' || type == 'C'){
        return PI * (radius * radius);
    }
    else{
        return 0.0;
    }
}
