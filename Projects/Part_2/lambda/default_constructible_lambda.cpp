#include <iostream>
#include <set>
#include <string>
#include <tuple> // For std::tie

using str = std::string;
using std::cout;

namespace {
    struct CPU {
        str name{};
        int coreCount{};
        int threadCount{};
    };
}

// Tie-breaker added: compares coreCount first, then threadCount, then name
static auto cpuMore = [](const CPU& a, const CPU& b) {
    return std::tie(a.coreCount, a.threadCount, a.name) >
           std::tie(b.coreCount, b.threadCount, b.name);
};

int main() {
    // 1. Fixed type from std::set<int, ...> to std::set<CPU, ...>
    std::set<CPU, decltype(cpuMore)> cpus;

    cpus.insert({"Ryzen 5 5600X", 6, 12});
    cpus.insert({"Core i9-13900K", 24, 32});
    cpus.insert({"Ryzen 7 7800X3D", 8, 16});
    cpus.insert({"Core i7-12700K", 12, 20});

    for (const auto& cpu : cpus) {
        cout << cpu.name << " - " << cpu.coreCount << " cores / " << cpu.threadCount << " threads\n";
    }

    // 2. C++20 Bonus: You can also write the lambda inline directly inside decltype!
    using CPUSet = std::set<CPU, decltype([](const CPU& a, const CPU& b) {
        return a.coreCount > b.coreCount;
    })>;
}