#include <iostream>
#include <vector>
#include <string>

using str = std::string;

int main(){
    std::vector<str> tasks;
    str taskAdd;
    int choice = 0;

    do{std::cout << "==== To-Do List ====\n\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Remove Task\n";
    std::cout << "3. List\n";
    std::cout << "4. Quit\n";
    std::cout << "Choice: ";
    std::cin >> choice;

    switch(choice){
        case 1:
            std::cout << "\nEnter name of task you would like to add: ";
            std::getline(std::cin >> std::ws, taskAdd);
            tasks.push_back(taskAdd);
            break;
        case 2:{
            int removalChoice = 0;
            std::cout << "==== Task Removal ====\n 1. Remove most recent task\n 2. Remove task by index\n Choice: ";
            std::cin >> removalChoice;

            switch(removalChoice){
                case 1:
                    tasks.pop_back();
                    break;
                case 2:{
                    int indexNumber = 0;
                    std::cout << "Enter the index number: ";
                    std::cin >> indexNumber;
                    tasks.erase(tasks.begin() + indexNumber);
                }    
            } 
            break;
        }
        case 3:{
            std::cout << "\n ==== Tasks ====\n";
            for (const str& t : tasks){
                std::cout << "- " << t << '\n';
            }
            break;

        }

        case 4:{
            break;
        }

        default:{
            std::cout << "Invalid input!\n";
            break;
        }


    }}while(choice != 4);

    return 0;
}