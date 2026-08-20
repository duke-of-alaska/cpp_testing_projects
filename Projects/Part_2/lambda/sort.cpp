#include <iostream>
#include <string>
#include <vector>
#include <ranges>

using str = std::string;
using std::vector;

namespace {
    struct Client {
        str name{};
        int age{};
    };
}

int main() {
    vector<Client> clients{
        {"John", 19},
        {"Mary", 53},
        {"Mark", 20}
    };

    auto clientsOver50 = clients | std::views::filter([](const Client& top) {
        return top.age > 50;
    });

    for (const auto& top : clientsOver50) {
        std::cout << top.name << " (" << top.age << ")\n";
    }

    return 0;
}