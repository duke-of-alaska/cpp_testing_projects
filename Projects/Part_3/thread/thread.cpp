#include <chrono>
#include <thread>
#include <iostream>

using namespace std::chrono_literals;

int main() {
    auto start = std::chrono::
    steady_clock::now();

    std::this_thread::sleep_for(1000ms);

    auto end = std::chrono::
    steady_clock::now();

    std::chrono::duration<double, std::milli> elapsed =
        end - start;

    std::cout << "Elapsed: " << elapsed.count() << '\n';
}