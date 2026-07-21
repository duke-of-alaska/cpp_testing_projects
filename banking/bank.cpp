#include <iostream>
#include <iomanip>

void showBalance(double Balance);
double deposit(double DepositAmount, double Balance);
double withdraw(double WithdrawAmount, double Balance);

int main(){
    int choice = 0;
    double Balance = 0.0;
    double amount = 0.0; // Declared once at the top for all cases

    do {
        std::cout << "\n===== Welcome to the Bank! =====\n";
        std::cout << "What would you like to do today?\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Quit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch(choice){
            case 1:
                showBalance(Balance);
                break;
            
            case 2:
                std::cout << "Enter the amount you want to deposit: $";
                std::cin >> amount;

                if (amount < 0) {
                    std::cout << "Invalid deposit amount!\n";
                } else {
                    Balance = deposit(amount, Balance);
                    std::cout << "You have successfully deposited $" << std::fixed << std::setprecision(2) << amount << " into your balance!\n";
                }
                break;

            case 3:
                std::cout << "Enter the amount you want to withdraw: $";
                std::cin >> amount;

                if (amount > Balance){
                    std::cout << "You cannot withdraw more than your balance!\n";
                } else if (amount < 0) {
                    std::cout << "Invalid withdrawal amount!\n";
                } else {
                    Balance = withdraw(amount, Balance);
                    std::cout << "You have successfully withdrawn $" << std::fixed << std::setprecision(2) << amount << " from your balance!\n";
                }
                break; // Fixed: Added missing break statement

            case 4:
                std::cout << "Thank you for using the bank! Goodbye.\n";
                return 0;
            
            default:
                std::cout << "Invalid input! Please choose 1-4.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

void showBalance(double Balance){
    std::cout << "Balance: $" << std::setprecision(2) << std::fixed << Balance << '\n';
}

double deposit(double DepositAmount, double Balance){
    return Balance + DepositAmount;
}

double withdraw(double WithdrawAmount, double Balance){
    return Balance - WithdrawAmount;
}