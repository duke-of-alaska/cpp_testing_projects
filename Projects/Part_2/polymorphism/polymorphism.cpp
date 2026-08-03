#include <iostream>
#include <memory>
#include <string>
#include <vector>

auto& print = std::cout;

class Nation{
public:
    virtual ~Nation() = default;

    virtual void capital() const = 0;
};

class Japan : public Nation{
public:
    void capital() const override{
        print << "Tokyo!\n";
    }
};

class Germany : public Nation{
public:
    void capital() const override{
        print << "Berlin!\n";
    }
};

class Spain : public Nation{
public:
    void capital() const override{
        print << "Madrid!\n";
    }
};

int main(){
    std::vector<std::unique_ptr<Nation>> globe;

    globe.push_back(std::make_unique<Japan>());
    globe.push_back(std::make_unique<Germany>());
    globe.push_back(std::make_unique<Spain>());

    for (const auto& nation : globe){
        nation->capital();
    }
}