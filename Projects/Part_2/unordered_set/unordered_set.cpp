#include <print>
#include <unordered_set>

using std::unordered_set;

int main() {
    unordered_set<int> s;

    s.insert(10);
    s.insert(20);

    for (int y : s) {
        std::print("{}\n", y);
    }

    return 0;
}