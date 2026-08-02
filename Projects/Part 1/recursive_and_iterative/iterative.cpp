#include <iostream>

constexpr auto& print = std::cout;

void walk(int steps);

int main(){
    int amountOfSteps{};
    print << "How many steps do you want to take? ";
    std::cin >> amountOfSteps;

	walk(amountOfSteps);
	return 0;
}

void walk (int steps){
	for (int i = 0; i < steps; i++){
		print << "You took a step!\n";
	}
}