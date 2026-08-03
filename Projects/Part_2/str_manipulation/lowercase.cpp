#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using str = std::string;
auto& print = std::cout;
auto& pass = std::cin;

int main(){
	str toLowercase = "Temp";

    print << "What string of text do you want to lowercase today? ";
    std::getline(pass >> std::ws, toLowercase);

	std::transform(toLowercase.begin(), toLowercase.end(), toLowercase.begin(), [](unsigned char c){
		return std::tolower(c);
	});

	std::cout << toLowercase << '\n';
    return 0;
}