#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::vector<int>> grid;

    grid.push_back({100, 500});
    grid.push_back({200, 201, 202});
    grid[0].push_back(109);

    grid[1].pop_back();

    for (size_t r = 0; r < grid.size(); ++r) {
        std::cout << "Row " << r << ": ";
        for (size_t c = 0; c < grid[r].size(); ++c) {
            std::cout << grid[r][c] << " "; // FIXED: added 'grid'
        }
        std::cout << '\n';
    }
}