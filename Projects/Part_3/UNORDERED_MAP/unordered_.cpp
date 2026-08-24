#include <iostream>
#include <string>
#include <unordered_map>

using std::unordered_map;
using str = std::string;

int main(){
    unordered_map<str, int> db;
    std::cout << "\n --- Populating DB... ---\n";

    // Insert Values
    db["John"] = 19;
    db["Cindy"] = 13;
    db["Burdie"] = 26;

    // Updating
    db["John"] = 17;

    // Size
    std::cout << db.size() << " unique items\n";

    // Instant-Lookup
    std::cout << "What to search?\n";
    str itemToSearch{};
    std::getline(std::cin >> std::ws, itemToSearch);

    auto it = db.find(itemToSearch);

    if (it != db.end()){
        std::cout << "Found " << (*it).first << " at age " << (*it).second << '\n';
    }
    else{
        std::cout << "Couldn't find it\n";
    }

    // Print Everything
    for(const auto& [name, age] : db){
        std::cout << "-" << name << ": " << age << " years old\n";
    }

    return 0;
}