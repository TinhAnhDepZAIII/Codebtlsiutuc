#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int sumMinMaxPosition(int* numbers, int num_elements) {
    int max_pos = 0, min_pos = 0;
    for (int i = 1; i < num_elements; i++) {
        if (numbers[i] > numbers[max_pos]) {
            max_pos = i;
        }
        if (numbers[i] < numbers[min_pos]) {
            min_pos = i;
        }
    }
    return max_pos + min_pos;
}

int main() {
    ifstream input_file("file.txt");
    

    string line;
    getline(input_file, line);
    
    int num_elements = stoi(line);

   getline(input_file, line);
    stringstream ss(line);
    
    
    

    int* numbers = new int[num_elements];
    for (int i = 0; i < num_elements; i++) {
        string number_str;
        getline(ss, number_str, ',');
        int number = stoi(number_str);
        numbers[i] = number;
    }

    int result = sumMinMaxPosition(numbers, num_elements);
    cout << result << endl;

   

    return 0;
}



