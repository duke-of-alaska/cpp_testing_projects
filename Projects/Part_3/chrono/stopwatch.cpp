#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;
using std::cout;

int main() {
    cout << "Enter length of stopwatch"
            "in seconds: \n";
    int e{};
    if (!(std::cin >> e)) {
        std::cerr << "Not a valid integer!\n";
        return 1;
    }

    auto d =
      std::chrono::steady_clock::now();

    for (int i = 1; i <= e; i++) {
        d += 1s;
        std::this_thread::sleep_until(d);
        cout << "Second: " << i << '\n';
    }
}