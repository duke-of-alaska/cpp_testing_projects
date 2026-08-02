#include <iostream>
#include <string>

using str = std::string;
constexpr auto& print = std::cout;
constexpr auto& pass = std::cin;

class Computer {
private:
    str CPU;
    int RAM;
    str GPU;
    str OS;
    int storage;

public:
    // Fast initializer list using const references
    Computer(const str& cpu, int ram, const str& gpu, const str& os, int store)
        : CPU{cpu}, RAM{ram}, GPU{gpu}, OS{os}, storage{store} {}

    void showSpecs() const {
        print << "CPU: " << CPU << "\n";
        print << "RAM: " << RAM << " GB\n";
        print << "GPU: " << GPU << "\n";
        print << "OS: " << OS << "\n";
        print << "Storage: " << storage << " GB\n";
    }
};

int main(){
    str CPU = "Temp";
    int RAM = 0;
    str GPU = "Temp";
    str OS = "Temp";
    int storage = 0;

    print << "Enter CPU: ";
    std::getline(pass >> std::ws, CPU);

    do{
        print << "Enter amount of RAM (in GB, numerals): ";
        pass >> RAM;
    } while(RAM <= 0);

    print << "Enter your GPU: ";
    std::getline(pass >> std::ws, GPU);

    print << "Enter your OS: ";
    std::getline(pass >> std::ws, OS);

    do{
        print << "Enter amount of storage (in GB, numerals): ";
        pass >> storage;
    } while(storage <= 0);

    if (CPU.empty() || GPU.empty() || OS.empty()) {
        print << "Error: CPU, GPU, and OS cannot be empty.\n";
        return 1;
    }

    Computer PC(CPU, RAM, GPU, OS, storage);
    print << "\nYour computer specs are:\n";
    PC.showSpecs();

}

