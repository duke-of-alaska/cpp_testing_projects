#include <iostream>
#include <string>

using str = std::string;
using std::cout;
using std::cin;

int main() {
    str plus = "CPU: ";

    auto cpu = []<typename C, typename I>(C a, I b){
        return a + b;
    };

    cout << "Enter CPU name:\n";
    str cpuName{};
    if (!(cin >> cpuName)) {
        return 1;
    };
    cout << cpu(plus, cpuName) << '\n';

}