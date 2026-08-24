#include <iostream>
#include <unordered_set>
#include <string>
  
struct Crush {
    std::string name;
    std::string school_era;
    int year_met;

    bool operator==(const Crush& other) const {
        return (name == other.name && school_era == other.school_era);
    }
};
namespace std {
    template <>
    struct hash<Crush> {
        size_t operator()(const Crush& c) const {
          
            size_t h1 = hash<string>{}(c.name);
            size_t h2 = hash<string>{}(c.school_era);
            return h1 ^ (h2 << 1); 
        }
    };
}

int main() {
    std::unordered_set<Crush> crush_db;

    std::cout << "--- Initializing CrushDB V1.0 (C++26) ---\n";

    crush_db.insert({"Jessica", "Middle School", 2014});
    crush_db.insert({"Sarah", "High School", 2017});
    crush_db.insert({"Emily", "University", 2021});

    std::cout << "Database loaded with " << crush_db.size() << " historical profiles.\n\n";

    std::cout << "--- Testing Duplicate Protection ---\n";
    
    auto [iterator, success] = crush_db.insert({"Sarah", "High School", 2018});

    if (!success) {
        std::cout << "Security Blocked: 'Sarah (High School)' is already logged in the DB!\n\n";
    }

    std::cout << "--- Querying Database Records ---\n";

    Crush target{"Jessica", "Middle School", 0}; 
    
    if (crush_db.contains(target)) {
        std::cout << "Search Hit: Reminiscence sequence found for Jessica.\n\n";
    } else {
        std::cout << "Search Miss: Individual not found in records.\n\n";
    }

    std::cout << "--- Displaying Full CrushDB Registry ---\n";
    
    for (const auto& person : crush_db) {
        std::cout << " | Name: " << person.name 
                  << " | Era: " << person.school_era 
                  << " | Met: " << person.year_met << "\n";
    }

    return 0;
}
