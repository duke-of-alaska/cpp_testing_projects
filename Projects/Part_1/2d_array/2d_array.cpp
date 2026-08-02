#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using str = std::string;
using strvector = std::vector<std::vector<str>>;

int main(){
    strvector nations = {
        {"Canada", "Brazil", "UK"},
        {"USA", "Croatia", "Tuvalu"},
        {"Guyana", "Suriname", "Italy"}
    };

    const int colWidth = 10;

    for (const auto& row : nations){
        for (const auto& column : row){
            std::cout << std::left << std::setw(colWidth) << column;
        }
        std::cout << '\n';
    }

    return 0;
}