#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int secondMaxInSequence(int newNumber[])
{
    int secondMaxx = -1;
    int second_pos = 0;
    if ((newNumber[0] > newNumber[1] && newNumber[0] < newNumber[2]) ||
        (newNumber[0] < newNumber[1] && newNumber[0] > newNumber[2]))
    {
        secondMaxx = newNumber[0];
    }

    if ((newNumber[1] > newNumber[0] && newNumber[1] < newNumber[2]) ||
        (newNumber[1] < newNumber[0] && newNumber[1] > newNumber[2]))
    {
        secondMaxx = newNumber[1];
        second_pos = 1;
    }

    if ((newNumber[2] > newNumber[0] && newNumber[2] < newNumber[1]) ||
        (newNumber[2] < newNumber[0] && newNumber[2] > newNumber[1]))
    {
        secondMaxx = newNumber[2];
        second_pos = 2;
    }

    if (secondMaxx < 0)
    {
        secondMaxx = -5;
        second_pos = -7;
    }
    return secondMaxx + second_pos;
}

int sumMinMaxPosition(int numbers[], int num_elements)
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
int ModifiedSequence2(int numbers[], int num_elements)
{
    int newNumber[num_elements];
    for (int i = 0; i < num_elements; i++)
    {
        if (numbers[i] < 0)
        {
            numbers[i] = -numbers[i];
        }

        newNumber[i] = (17 * numbers[i] + 9) % 257;
    }
    int result = secondMaxInSequence(newNumber);
    return result;
}

int ModifiedSequence(int numbers[], int num_elements)
{
    int newNumber[num_elements];
    for (int i = 0; i < num_elements; i++)
    {
        if (numbers[i] < 0)
        {
            numbers[i] = -numbers[i];
        }

        newNumber[i] = (17 * numbers[i] + 9) % 257;
    }

    int results = sumMinMaxPosition(newNumber, num_elements);

    return results;
}

int MaxPosValueInSequence(int numbers[], int num_elemnts)
{

    int peak_pos = -3; // initialize to default values
    int peak_value = -2;

    // look for the peak
    for (int i = 0; i < num_elemnts; i++)
    {
        if (i == 0 && numbers[i] > numbers[i+1]) {
            // peak at beginning of sequence
            peak_pos = i;
            peak_value = numbers[i];
            break;
        } else if (i == num_elemnts-1 && numbers[i] > numbers[i-1]) {
            // peak at end of sequence
            peak_pos = i;
            peak_value = numbers[i];
            break;
        } else if (i > 0 && i < num_elemnts-1 && numbers[i] > numbers[i-1] && numbers[i] > numbers[i+1]) {
            // peak in middle of sequence
            peak_pos = i;
            peak_value = numbers[i];
            break;
        }
    }

    // check if sequence has mountain shape
    if (peak_pos == -3 || peak_value ==-2) {
        // no mountain shape or peak at beginning/end of sequence
        peak_pos = -3;
        peak_value = -2;
    } else {
        // check if sequence strictly increases before peak and strictly decreases after peak
        int i;
        for (i = 0; i < peak_pos; i++) {
            if (numbers[i] >= numbers[i+1]) {
                break;
            }
        }
        for (; i < num_elemnts-1; i++) {
            if (numbers[i] <= numbers[i+1]) {
                break;
            }
        }
        if (i < num_elemnts-1) {
            // sequence does not have mountain shape
            peak_pos = -3;
            peak_value = -2;
        }
    }

    return peak_pos + peak_value;
}
// int MaxValueInSequence(int *numbers, int num_elements)
// {
//     int summit_pos = 0;
//     int summit_value = 0;
//     int initial = numbers[0];
//     int countLegit = 0;
//     int notGoDownHill = 0;

//     for (int i = 1; i < num_elements; i++)
//     {

//         if (numbers[i] > initial)
//         {
//             initial = numbers[i];
//             summit_pos = i;
//             summit_value = numbers[i];
//             notGoDownHill = 1;
//             if (countLegit == 1)
//             {

//                 summit_pos = -3;
//                 summit_value = -2;
//                 break;
//             }
//         }
//         else if (numbers[i] == initial)
//         {
//         }
//         else
//         {
//             if (notGoDownHill)
//             {
//                 initial = numbers[i];
//                 countLegit = 1;
//             }
//             else
//             {
//                 summit_pos = 0;
//                 summit_value = initial;
//             }
//         }
//     }
//     return summit_value;
// }

int numElementss(string filename)
{
    ifstream fileInput(filename);
    string line;
    getline(fileInput, line);
    return stoi(line);
}

void ExtractNumMush(string filename, int numbers[])
{

    ifstream fileInput(filename);
    string line;
    getline(fileInput, line);
    int numElements = stoi(line);
    getline(fileInput, line);
    stringstream ss(line);

    for (int i = 0; i < numElements; i++)
    {
        string str;
        getline(ss, str, ',');
        int number = stoi(str);
        numbers[i] = number;
    }
}
bool Event13Verify(string s, int len)
{
    if (s[0] == '1' && s[1] == '3')
    {
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
    while (infile >> n2)
    {
        int len = n2.length();

        string num = ExtractMush(n2, len);

        int lenNum = num.length();

        for (int i = 0; i < lenNum; i++)
        {
            int digit = num[i] - '0';
            int numm = numElementss("file.txt");
            int N1[numm];
            ExtractNumMush("file.txt", N1);
            if (digit == 1)

            {

                int results = sumMinMaxPosition(N1, numm);
                cout << results << endl;
            }

            if (digit == 2)
            {

                int summit_result = MaxPosValueInSequence(N1, numm);

                cout << summit_result << endl;
            }
            if (digit == 3)
            {

                int results = ModifiedSequence(N1, numm);
                cout << results << endl;
            }

            if (digit == 4)
            {
                cout << ModifiedSequence2(N1, numm);
            }
        }
    }
    return 0;
}