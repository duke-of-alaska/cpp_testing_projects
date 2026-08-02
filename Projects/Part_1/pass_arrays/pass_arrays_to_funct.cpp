#include <iostream>
#include <vector>

void printNumbers(const std::vector<int>& integers);

int main(){
    std::vector<int> numbers = {1 , 2, 3};
    printNumbers(numbers);

    return 0;
}

void printNumbers(const std::vector<int>& integers){
    for (const int& num : integers){
        std::cout << "- " << num << '\n';
    }
}