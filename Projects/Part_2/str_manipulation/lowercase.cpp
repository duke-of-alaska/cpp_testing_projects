#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using str = std::string;
auto& print = std::cout;
auto& pass = std::cin;

str lowercaseAlgo(str& input);

int main(){
	str toLowercase = "Temp";

    print << "Enter string to lowercase: ";
    std::getline(pass >> std::ws, toLowercase);

	toLowercase = lowercaseAlgo(toLowercase);

	std::cout << toLowercase << '\n';
    return 0;
}

str lowercaseAlgo(str& input){
	std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c){
		return std::tolower(c);
	});
	return input;
}