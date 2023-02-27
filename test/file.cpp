#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream ifs("file.txt");
    std::string line;
    std::getline(ifs, line);
    std::stringstream ss(line);
    std::stringstream ss2(line);

    std::string line1, line2;
    ss>>line1;
    ss2>>line2;
    std::cout<<line1<<" "<< line2;
    return 0;
}