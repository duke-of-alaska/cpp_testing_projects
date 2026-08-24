#include <iostream>
#include <unordered_map>
#include <string>

// Our custom object blueprint
struct Pokemon {
    std::string name;
    std::string type;
    int level;
    std::string evolution_form;
};

int main() {
    // Key: Slot Number (int) | Value: Our custom object (Pokemon)
    std::unordered_map<int, Pokemon> party;

    std::cout << "--- Catching Pokemon (Inserting Custom Objects) ---\n";

    // Method A: Direct assignment using uniform initialization {}
    party[1] = Pokemon{"Pichu", "Electric", 12, "Pikachu"};
    party[2] = Pokemon{"Charmander", "Fire", 14, "Charmeleon"};

    // Method B: Using .insert() with a nested pair
    party.insert({3, Pokemon{"Caterpie", "Bug", 6, "Metapod"}});

    std::cout << "Party size: " << party.size() << " Pokemon ready!\n\n";

    std::cout << "--- The Evolution Phase ---\n";

    // Let's evolve the Pokemon in slot 1 (Pichu -> Pikachu)
    int slot_to_evolve = 1;
    
    // Find the item safely using a pointer iterator
    auto it = party.find(slot_to_evolve);

    if (it != party.end()) {
        // 'it->second' points directly to our custom Pokemon struct
        std::cout << "What? " << it->second.name << " is evolving!\n";
        
        // Update the custom object's internal variables
        it->second.name = it->second.evolution_form; // Change name to "Pikachu"
        it->second.level += 1;                       // Level up
        it->second.evolution_form = "Raichu";        // Update next evolution stage
        
        std::cout << "Congratulations! It evolved into " << it->second.name << " (Level " << it->second.level << ")!\n\n";
    }

    std::cout << "--- Inspecting Full Trainer Party ---\n";
    
    // Using C++ Structured Binding to unpack the slot number andd the custom object
    for (const auto& [slot, pokemon] : party) {
        std::cout << "Slot [" << slot << "]: " 
                  << pokemon.name << " | Type: " << pokemon.type 
                  << " | Level: " << pokemon.level 
                  << " | Next Form: " << pokemon.evolution_form << "\n";
    }

    return 0;
}
