#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;
using std::cout;

int main() {
    cout << "Enter length of stopwatch"
            "in seconds: \n";
    int d{};
    if (!(std::cin >> d)) {
        std::cerr << "Not a valid integer!\n";
        return 1;
    }

    auto e =
      std::chrono::steady_clock::now();

    for (int i = 1; i <= d; i++) {
        e += 1s;
        std::this_thread::sleep_until(e);
        cout << "Second: " << i << '\n';
    }
}