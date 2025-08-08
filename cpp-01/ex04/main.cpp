#include <fstream>
#include <iostream>
#include <string>

std::string line_c(std::string line, char **argv) {
    std::string uline;
    char c;
    std::string s1(argv[1]);
    std::string s2(argv[2]);
    while (c != '\0') {
        int size = line.find(s1);
        
    }
    return uline;
}
int main(int argc, char **argv) {
    (void)argc;
    std::ifstream infile(argv[3]);
    std::string cfile;
    std::string line;
    while (std::getline(infile, line)) {
        std::string update_line;
        update_line = line_c(line, argv);
        cfile += update_line;
    }
    infile.close();

    std::ofstream outfile(argv[3], std::ios::trunc);
    outfile << cfile;
    outfile.close();

    std::cout << cfile;
}
