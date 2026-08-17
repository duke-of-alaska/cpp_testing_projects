#include <iostream>
#include <string>

using str = std::string;
using std::cout, std::cin;

int main() {
    str mark = "watermark";
    
    auto watermarker = [mark](const str& basicStr) {
        return basicStr + " " + mark;
    };

    cout << "Enter string to watermark:\n";
    str testStr = {};
    if (!(cin >> testStr)) {
        std::cerr << "not a valid string!\n";
        return 1;
    }
    cout  << watermarker(testStr) << '\n';
    return 0;
    
}