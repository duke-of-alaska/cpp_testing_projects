#include <iostream>

using str = std::string;
constexpr auto& print = std::cout;

struct student{
    // Initialise values with default values
	str name = "Temp";
	int score = 0;
	bool enrolled = false;
};

int main(){

	student student_a;

	student_a.name = "Bob";
	student_a.score = 73;
	student_a.enrolled = true;

    print << "Name: " << student_a.name << '\n';

    student student_b = {"Joe", 75, true};
    print << "Name: " << student_b.name << '\n';

	return 0;
}