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

int main()
{
    ifstream input_file("file.txt");

    string line;
    getline(input_file, line);

    int num_elements = stoi(line);

    getline(input_file, line);
    stringstream ss(line);

    int *numbers = new int[num_elements];
    for (int i = 0; i < num_elements; i++)
    {
        string number_str;
        getline(ss, number_str, ',');
        int number = stoi(number_str);
        numbers[i] = number;
    }

    // int result = sumMinMaxPosition(numbers, num_elements);
    // cout << result << endl;
    // int summit_pos =0;
    // int summit_value =0;
    // int initial = numbers[0];
    // int countLegit=0;
    // int notGoDownHill=0;

    // for (int i = 1; i < num_elements; i++)
    // {
        
    //     if (numbers[i] > initial)
    //     {
    //         initial = numbers[i];
    //         summit_pos =i;
    //         summit_value = numbers[i];
    //         notGoDownHill=1;
    //         if(countLegit==1){
    //             cout<<" Not the right sequence of number"<<endl;
                
    //             summit_pos=-3;
    //             summit_value=-2;
    //             break;
    //         }
    //     }
    //     else if (numbers[i] == initial)
    //     {
    //     }
    //     else
    //     {
    //         if(notGoDownHill){
    //         initial = numbers[i];
    //         countLegit=1;
    //         }
    //         else 
    //         {
    //             summit_pos=0;
    //             summit_value =initial;
    //         }
            

    //     }
    // }

    // cout<<summit_pos<<endl;
    // cout<<summit_value<<endl;


    int *newNumber = new int [num_elements];
    for ( int i=0; i<num_elements; i++){
        if ( numbers[i]<0){
            newNumber[i]= - numbers[i];
        }
        else
        {
            newNumber[i]= (17 * numbers[i]+9)%257;

        }
    }
    for ( int i=0; i<num_elements;i++){
        cout<<newNumber[i]<<endl;
    }

    // int results = sumMinMaxPosition(newNumber,  num_elements);

    
    int secondMaxx=0;
    if ( (newNumber[0]> newNumber[1] && newNumber[0]< newNumber[2]) || 
    (newNumber[0]< newNumber[1] && newNumber[0]> newNumber[2])){
        secondMaxx= newNumber[0];
    }

    if ( (newNumber[1]> newNumber[0] && newNumber[1]< newNumber[2]) || 
    (newNumber[1]< newNumber[0] && newNumber[1]> newNumber[2])){
        secondMaxx= newNumber[1];
    }

    if ( (newNumber[2]> newNumber[0] && newNumber[2]< newNumber[1]) || 
    (newNumber[2]< newNumber[0] && newNumber[2]> newNumber[1])){
        secondMaxx= newNumber[2];
        }
    
    
    cout<<secondMaxx;


    delete[] newNumber;
    delete[] numbers;

    




    return 0;
}
