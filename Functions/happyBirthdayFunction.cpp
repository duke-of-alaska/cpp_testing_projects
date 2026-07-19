#include <iostream>
#include <string>

using str_t = std::string;

void happyBirthday(str_t name){
    std::cout << "Happy birthday, " << name << "!" << '\n';
}

void notHappyBirthday(str_t name){
    std::cout << "Have a great day, " << name << "!" << '\n';
}

int main(){
    char askForConfirmation;
    str_t name;

    std::cout << "Is it your birthday today? (y/n): ";
    std::cin >> askForConfirmation;

    std::cout << "What is your name, then? ";
    std::getline(std::cin >> std::ws, name);

    if(askForConfirmation == 'y' || askForConfirmation == 'Y'){
        happyBirthday(name);
    } else {
        notHappyBirthday(name);
    }
}