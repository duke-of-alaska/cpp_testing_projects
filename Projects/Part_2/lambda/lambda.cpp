#include <iostream>

int main(){
	int a, b;

	auto multiply = [](int a, int b){
	return a * b;
	};

	std::cout << "First number: ";
	std::cin >> a;

	std::cout << "Second number: ";
	std::cin >> b;

	int result = multiply(a, b);
	std::cout << result << '\n';
	
	return 0;
}