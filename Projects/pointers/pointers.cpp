#include <iostream>

constexpr auto& print = std::cout;

int main(){
    int u = 10;
    int *pU = &u;

    print << *pU;
    return 0;
}