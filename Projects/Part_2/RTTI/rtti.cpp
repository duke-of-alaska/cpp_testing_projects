#include <iostream>
#include <memory>
#include <vector>

class Country {
public:
    virtual ~Country() = default; // Fix 1: Added = default;
};

class Indonesia : public Country {
public:
    void indonesianBankAccount() const {
        std::cout << "Accessing Indonesian bank account!\n";
    }
};

class Switzerland : public Country {};

int main() {
    std::vector<std::unique_ptr<Country>> border;
    border.push_back(std::make_unique<Indonesia>());
    border.push_back(std::make_unique<Switzerland>());

    for (const auto& country : border) {
        Indonesia* indo = dynamic_cast<Indonesia*>(country.get());

        if (indo) {
            indo->indonesianBankAccount(); // Fix 2: Added ()
        } else {
            std::cout << "Not Indonesia!\n";
        }
    }
}