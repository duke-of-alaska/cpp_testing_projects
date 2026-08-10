#include <iostream>

int adder(int a, int b);

int main(){
    std::cout << "Welcome to the sum (by lambda) program!\n";

	std::cout << "Enter first number: ";
	int a{};
	if (!(std::cin >> a)){
        std::cerr << "Not an integer!\n";
        return 1;
    }

	std::cout << "Enter second number: ";
	int b{};
	if (!(std::cin >> b)){
        std::cerr << "Not an integer!\n";
        return 1;
    }

	const int result = adder(a, b);
	std::cout << "Sum: " << result << '\n';
	
	return 0;
}

int adder(int a, int b){
	return a + b;
}