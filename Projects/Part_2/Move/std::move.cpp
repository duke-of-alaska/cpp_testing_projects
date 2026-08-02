#include <iostream>
#include <string>
#include <utility>

using str = std::string;
auto& print = std::cout;

int main(){
    str string = "Hello!";

    str cpy = string; 
    print << "src after copy: " << string << "\n"; // COPY

    str mov = std::move(string); 
    print << "src after move: " << string << "\n"; // NOW EMPTY!
    print << "mov:            " << mov << "\n"; // Holds data
}