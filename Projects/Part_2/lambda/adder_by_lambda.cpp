#include <iostream>


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

	auto adder = [](int a, int b) {
		return a + b;
	};

	const int result = adder(a, b);
	std::cout << "Sum: " << result << '\n';
	
	return 0;
}