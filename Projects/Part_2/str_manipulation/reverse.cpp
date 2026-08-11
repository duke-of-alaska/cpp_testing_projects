#include <iostream>
#include <string>
#include <algorithm>

using str = std::string;
static auto& print = std::cout;
static auto& pass = std::cin;

str reverseAlgo(str toReverse);

int main(){
	str toReverse = "Temp";
	print << "Enter string to reverse: ";
	std::getline(pass >> std::ws, toReverse);

	str reversed = reverseAlgo(toReverse);
    print << reversed << '\n';

	return 0;
}

// Function to reverse a string using the std::reverse algorithm
str reverseAlgo(str toReverse){
    std::reverse(toReverse.begin(), toReverse.end());
    return toReverse;
}