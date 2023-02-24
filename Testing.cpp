#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    fstream file;
    file.open("tc1_input", ios::in);

    if (!file.is_open()) {
        cout << "File not found" << endl;
        return 1;
    }

    // Line 1
    string line;
    getline(file, line);
    stringstream ss(line);
    int num1, num2, num3, num4, num5;
    ss >> num1 >> num2 >> num3 >> num4 >> num5;

    // Line 2
    getline(file, line);
    int num6 = stoi(line);

    // Line 3
    getline(file, line);
    stringstream ss2(line);
    string pack1, pack2, pack3;
    getline(ss2, pack1, ',');
    getline(ss2, pack2, ',');
    getline(ss2, pack3);

    // Output
    cout << "Numbers: " << num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << endl;
    cout << "Number of packs: " << num6 << endl;
    cout << "Packs: " << pack1 << " " << pack2 << " " << pack3 << endl;

    // Close file
    file.close();

    return 0;
}