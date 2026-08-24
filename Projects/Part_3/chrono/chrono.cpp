#include <chrono>
#include <iostream>

using namespace std::chrono_literals;
using std::cout;

int main() {
    auto sec = 10s;
    auto ms = 10ms;

    std::chrono::milliseconds total = sec + ms;

    auto truncated = std::chrono::duration_cast<
        std::chrono::seconds>(total);

    cout << total.count() << "ms\n";
    cout << truncated.count() << "s\n";

    return 0;
}