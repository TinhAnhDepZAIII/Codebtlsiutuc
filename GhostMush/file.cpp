#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int secondMaxInSequence(int *newNumber)
{
    int secondMaxx = -1;
    int second_pos =0;
    if ((newNumber[0] > newNumber[1] && newNumber[0] < newNumber[2]) ||
        (newNumber[0] < newNumber[1] && newNumber[0] > newNumber[2]))
    {
        secondMaxx = newNumber[0];
        

    }

    if ((newNumber[1] > newNumber[0] && newNumber[1] < newNumber[2]) ||
        (newNumber[1] < newNumber[0] && newNumber[1] > newNumber[2]))
    {
        secondMaxx = newNumber[1];
        second_pos=1;
    }

    if ((newNumber[2] > newNumber[0] && newNumber[2] < newNumber[1]) ||
        (newNumber[2] < newNumber[0] && newNumber[2] > newNumber[1]))
    {
        secondMaxx = newNumber[2];
        second_pos =2;

    }

    if (secondMaxx< 0){
        secondMaxx =-5;
        second_pos =-7;
    }
    return secondMaxx+second_pos;
}

int sumMinMaxPosition(int *numbers, int num_elements)
{
    int max = 0, min = 0;
    for (int i = 1; i < num_elements; i++)
    {
        if (numbers[i] > numbers[max])
        {
            max = i;
        }
        if (numbers[i] < numbers[min])
        {
            min = i;
        }
    }
    return max + min;
}
int *ModifiedSequence2(int *numbers, int num_elements)
{
    int *newNumber = new int[num_elements];
    for (int i = 0; i < num_elements; i++)
    {
        if (numbers[i] < 0)
        {
            newNumber[i] = -numbers[i];
        }
        else
        {
            newNumber[i] = (17 * numbers[i] + 9) % 257;
        }
    }
    return newNumber;
}

int ModifiedSequence(int *numbers, int num_elements)
{
    int *newNumber = new int[num_elements];
    for (int i = 0; i < num_elements; i++)
    {
        if (numbers[i] < 0)
        {
            newNumber[i] = -numbers[i];
        }
        else
        {
            newNumber[i] = (17 * numbers[i] + 9) % 257;
        }
    }

    int results = sumMinMaxPosition(newNumber, num_elements);
    delete[] newNumber;
    delete[] numbers;
    return results;
}

int MaxPosInSequence(int *numbers, int num_elemnts)
{

    int summit_pos = 0;
    int summit_value = 0;
    int initial = numbers[0];
    int countLegit = 0;
    int notGoDownHill = 0;

    for (int i = 1; i < num_elemnts; i++)
    {

        if (numbers[i] > initial)
        {
            initial = numbers[i];
            summit_pos = i;
            summit_value = numbers[i];
            notGoDownHill = 1;
            if (countLegit == 1)
            {

                summit_pos = -3;
                summit_value = -2;
                break;
            }
        }
        else if (numbers[i] == initial)
        {
        }
        else
        {
            if (notGoDownHill)
            {
                initial = numbers[i];
                countLegit = 1;
            }
            else
            {
                summit_pos = 0;
                summit_value = initial;
            }
        }
    }
    return summit_pos;
}
int MaxValueInSequence(int *numbers, int num_elements)
{
    int summit_pos = 0;
    int summit_value = 0;
    int initial = numbers[0];
    int countLegit = 0;
    int notGoDownHill = 0;

    for (int i = 1; i < num_elements; i++)
    {

        if (numbers[i] > initial)
        {
            initial = numbers[i];
            summit_pos = i;
            summit_value = numbers[i];
            notGoDownHill = 1;
            if (countLegit == 1)
            {

                summit_pos = -3;
                summit_value = -2;
                break;
            }
        }
        else if (numbers[i] == initial)
        {
        }
        else
        {
            if (notGoDownHill)
            {
                initial = numbers[i];
                countLegit = 1;
            }
            else
            {
                summit_pos = 0;
                summit_value = initial;
            }
        }
    }
    return summit_value;
}

int numElementss(string filename)
{
    ifstream fileInput(filename);
    string line;
    getline(fileInput, line);
    return stoi(line);
}

int *ExtractNumMush(string filename)
{

    ifstream fileInput(filename);
    string line;
    getline(fileInput, line);
    int numElements = stoi(line);
    getline(fileInput, line);
    stringstream ss(line);

    int *numbers = new int[numElements];

    for (int i = 0; i < numElements; i++)
    {
        string str;
        getline(ss, str, ',');
        int number = stoi(str);
        numbers[i] = number;
    }
    return numbers;
}
bool Event13Verify(string s,int len){
    if ( s[0]=='1' && s[1]=='3'){
        return true;
    }
    return false;

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
    while (infile >>n2){
        int len = n2.length();

        bool verify = Event13Verify(n2,len);
        cout<<verify<<endl;

        // string num = ExtractMush(n2, len);

        // int lenNum = num.length();

        
        // for (int i = 0; i < lenNum; i++)
        // {
        //     int digit = num[i] - '0';
        //     if (digit == 1)
        //     {
        //         int numm = numElementss("file.txt");
        //         int *N1 = new int[numm];
        //         N1 = ExtractNumMush("file.txt");

        //         int results = sumMinMaxPosition(N1, numm);
        //         cout << results << endl;
        //     }

        //     if (digit == 2)
        //     {
        //         int num2 = numElementss("file.txt");
        //         int *N2 = new int[num2];
        //         N2 = ExtractNumMush("file.txt");
        //         int summit_pos = MaxPosInSequence(N2, num2);
        //         int summit_value = MaxValueInSequence(N2, num2);
        //         cout << summit_pos << " " << summit_value << endl;
        //     }
        //     if (digit == 3)
        //     {
        //         int num3 = numElementss("file.txt");
        //         int *N3 = new int[num3];
        //         N3 = ExtractNumMush("file.txt");
        //         int results = ModifiedSequence(N3, num3);
        //         cout << results<<endl;
        //     }

        //     if (digit == 4)
        //     {
        //         int num4 = numElementss("file.txt");
        //         int *N4 = new int[num4];
        //         N4 = ExtractNumMush("file.txt");
        //         int *N41 = new int[3];
        //         N41 = ModifiedSequence2(N4, 3);
        //         int results = secondMaxInSequence(N41);
        //         cout << results;
        //     }

        // }
    }
    return 0;
}