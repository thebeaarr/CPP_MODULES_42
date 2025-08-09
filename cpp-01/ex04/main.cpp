#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {

    if(argc == 4)
    {
        std::ifstream infile(argv[3]);
        std::string s1(argv[1]);
        std::string s2(argv[2]);
        std::string cfile;
        std::string line;
        while (std::getline(infile, line))
        {
            std::string::size_type pos = 0;
            std::string::size_type found;
            std::string update_line; // replacing means that we remove s1 and replace by s2
            while(true)
            {
                found = line.find(s1 , pos);
                if (found == std::string::npos)
                {
                    update_line += line.substr(pos);
                    break;
                }
                update_line += line.substr(0 ,found - pos);
                update_line += s2;
                pos = found + s1.size();
            }
            cfile += update_line + '\n';
        }
        infile.close();
        std::ofstream outfile(argv[3], std::ios::trunc);
        outfile << cfile;
        outfile.close();
        std::cout << cfile;
    }
    else
        std::cerr << "error.3 params make sure next time." << std::endl;
}
