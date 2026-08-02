#include <iostream>

using str = std::string;

void swap(str &x, str &y);

int main(){
    str x = "Soda";
    str y = "Water";

    swap(x, y);
    
    std::cout << x << '\n';
    std::cout << y << '\n';
    return 0;

}

void swap(str &x, str &y){
    str temp;

    temp = x;
    x = y;
    y = temp;
}