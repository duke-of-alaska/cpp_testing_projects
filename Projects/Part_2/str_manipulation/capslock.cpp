#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using str = std::string;
auto& print = std::cout;
auto& pass = std::cin;

str capslockAlgo(str& input);

int main(){
	str toCAPSLOCK = "Temp";

    print << "Enter string to capslock: ";
    std::getline(pass >> std::ws, toCAPSLOCK);

	toCAPSLOCK = capslockAlgo(toCAPSLOCK);

	std::cout << toCAPSLOCK << '\n';
    return 0;
}

str capslockAlgo(str& input){
	std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c){
		return std::toupper(c);
	});
	return input;
}