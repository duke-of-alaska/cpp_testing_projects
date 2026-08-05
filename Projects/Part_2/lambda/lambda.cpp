#include <iostream>

int main(){
	auto multiply = [](int a, int b){
	return a * b;
	};

	int result = multiply(4, 5);
	std::cout << result << '\n';
}


