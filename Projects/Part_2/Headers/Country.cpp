#include "Country.hpp"

// Constructor implementation
Country::Country(std::string countryName) : name(countryName) {}

// Method implementation
void Country::printInfo() const {
    std::cout << "Country: " << name << "\n";
}