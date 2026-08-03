#include <iostream>
#include <string>
#include <memory>

auto& print = std::cout;
using str = std::string;

class Nation{
public:
    virtual ~Nation() = default;

    void statement(){
        print << "This is a nation.\n";
    }

    virtual void name(str name){
        print << "Name: " << name << '\n';
    }
};

class Japan : public Nation{
public:
    void statement(){
        print << "Japan normal.\n";
    }

    void name(str name) override{
        print << "Name: " << name << '\n';
    }
};

int main(){
    str name = "Japan";
    std::unique_ptr<Nation> nation1 = std::make_unique<Japan>();
    nation1->statement();
    nation1->name(name);
    print << "Done!\n";
}