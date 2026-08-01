#include <iostream>
#include <string>

using str = std::string;
constexpr auto& pass = std::cin;
constexpr auto& print = std::cout;

int getDigit(const int number);
int sumOddDigits (const str& cardNumber);
int sumEvenDigits (const str& cardNumber);

int main(){
    str cardNumber = "tempValue";
    int result{};

    print << "Enter a credit card number: ";
    pass >> cardNumber;

    result = sumOddDigits(cardNumber) + sumEvenDigits(cardNumber);

    if(result % 10 == 0){
        print << "Valid.\n";
    }
    else{
        print << "Invalid.\n";
    }


    return 0;
}

int getDigit(const int number){
    return number % 10 + ((number / 10) % 10);
}
int sumOddDigits (const str& cardNumber){
    int sum = 0;

    for(int i = cardNumber.size() - 1; i >= 0; i -= 2){
        sum += cardNumber[i] - '0';
    }
    return sum;
}
int sumEvenDigits (const str& cardNumber){
    int sum = 0;

    for(int i = cardNumber.size() - 2; i >= 0; i -= 2){
        sum += getDigit((cardNumber[i] - '0') * 2);
    }
    return sum;
}