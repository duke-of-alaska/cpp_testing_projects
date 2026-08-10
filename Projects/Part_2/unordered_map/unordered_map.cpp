#include <unordered_map>
#include <iostream> // Swapped out <print> to avoid the compiler bug
#include <string>

using str = std::string;

int main(){
    std::unordered_map<str, str> editor = {
        {"neovim", "terminal"},
        {"clion", "gui"}
    };

    editor["vim"] = "old but reliable";
    editor.insert({"vscode", "very standard"});

    if(str choice = "neovim"; editor.contains(choice)){
        std::cout << choice << ": " << editor[choice] << "\n";
    }
    else{
        std::cout << "No neovim.\n";
    }

    if(auto it = editor.find("eclipse"); it != editor.end()){
        std::cout << "Eclipse founded!\n";
    }
    else{
        std::cout << "No Eclipse.\n";
    }

    std::cout << "\nAll\n";

    for (const auto& [name, description] : editor){
        std::cout << name << ": " << description << "\n";
    }

    return 0;
}
