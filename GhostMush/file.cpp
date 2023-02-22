#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int sumMinMaxPosition(int* numbers, int num_elements) {
    int max = 0, min = 0;
    for (int i = 1; i < num_elements; i++) {
        if (numbers[i] > numbers[max]) {
            max = i;
        }
        if (numbers[i] < numbers[min]) {
            min= i;
        }
    }
    return max + min;
}

int ExtractNumMush(string filename, int *numbers){

    ifstream fileInput(filename);
    string line;
    getline(fileInput, line);
    int num_elements = stoi(line);
    getline(fileInput, line);
    stringstream ss(line);
    

    for ( int i =0; i<num_elements; i++){
        string str;
        getline(ss, str, ',');
        int number = stoi(str);
        numbers[i]= number;


        
    }
    int result = sumMinMaxPosition(numbers, num_elements);
    return result;
    

}

string ExtractMush(string s, int len)
{
    string outstr;
    if (s[0] == '1' && s[1] == '3')
    {
        stringstream ss;
        for (int i = 2; i < len; i++)
        {
            ss << s[i];
        }
        outstr = ss.str();
    }
    return outstr;
}

int main()
{
    string n2;
    ifstream infile("KoopaEvent.txt");
    infile >> n2;
    int len = n2.length();

    string num = ExtractMush(n2, len);
    
    

    int lenNum = num.length();
    for (int i = 0; i < lenNum; i++)
    {
        int digit = num[i]-'0';
        switch (digit)
        {
        case 1:
            int *N1= new int[20];
            int results = ExtractNumMush("file.txt", N1);
            cout << results;
            
            
            break;
        case 2:
            
        }

    }
    return 0;
}