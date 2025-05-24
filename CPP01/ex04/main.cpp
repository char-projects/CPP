#include <iostream>
#include <fstream>
#include <string>

void file(std::string filename, std::string s1, std::string s2) {
    std::ifstream file;
    std::string line;
    std::string newLine = "";
    std::string text = "";
    std::string newFilename;
    
    std::cout << "Filename: " << filename << std::endl;
    file.open(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    while (file.good()) {
        while(std::getline(file, line)) {
            std::cout << "Old content: " << line << std::endl;
            for (size_t i = 0; i < line.length(); ) {
                if (line.substr(i, s1.length()) == s1 && !s1.empty()) {
                    newLine += s2;
                    i += s1.length();
                } else {
                    newLine += line[i];
                    i++;
                }
            }
            text += newLine + "\n";
            std::cout << "New content: " << newLine << std::endl;
        }
        file.close();
    }
    newFilename = filename + ".replace";
    std::ofstream newFile(newFilename.c_str());
    if (!newFile.is_open()) {
        std::cerr << "Error: Could not create file " << filename + ".replace" << std::endl;
        return;
    }
    std::cout << "File " << newFilename << " created successfully" << std::endl;
    newFile << text;
    std::cout << "New content copied to " << newFilename << std::endl;
    file.close();
    newFile.close();
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    file(argv[1], argv[2], argv[3]);
}
