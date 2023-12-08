#include "SHA256.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    SHA256 sha256;
    std::ifstream file("Downloads\\mark.txt");
    std::string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            sha256.update(reinterpret_cast<const uint8_t*>(line.c_str()), line.size());
        }
        file.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
        return 1;
    }

    std::array<uint8_t,32> digest = sha256.digest();
    std::string hash = sha256.toString(digest);

    std::cout << "SHA256 Hash: " << hash << std::endl;

    return 0;
}
