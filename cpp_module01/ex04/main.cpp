#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc == 4) {
        std::ifstream infile(argv[3]);
        if (!infile.is_open()) {
            std::cerr << "Error: cannot open file " << argv[3] << std::endl;
            return 1;
        }

        std::string s1(argv[1]);
        std::string s2(argv[2]);
        if (s1.empty() || s2.empty()) {
            std::cerr << "Error: empty string argument." << std::endl;
            return 1;
        }

        std::string cfile;
        std::string line;
        while (std::getline(infile, line)) {
            std::string::size_type pos = 0;
            std::string::size_type found;
            std::string update_line;

            while ((found = line.find(s1, pos)) != std::string::npos) {
                update_line += line.substr(pos, found - pos);
                update_line += s2;
                pos = found + s1.size();
            }
            update_line += line.substr(pos);
            cfile += update_line + '\n';
        }

        std::string rep = std::string(argv[3]) + ".replace";
        std::ofstream outfile(rep.c_str(), std::ios::trunc);
        if (!outfile.is_open()) {
            std::cerr << "Error: cannot write to file " << rep << std::endl;
            return 1;
        }

        outfile << cfile;
        std::cout << "Replacement done! Output file: " << rep << std::endl;
    }
    else {
        std::cerr << "Usage: " << argv[0] << " <s1> <s2> <filename>" << std::endl;
    }
}
