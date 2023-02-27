#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


bool ContainMerlin(string s) {
    for (int i = 0; i < 6; i++) {
        if (tolower(s[i]) == 'm' &&
            tolower(s[i+1]) == 'e' &&
            tolower(s[i+2]) == 'r' &&
            tolower(s[i+3]) == 'l' &&
            tolower(s[i+4]) == 'i' &&
            tolower(s[i+5]) == 'n') {
                return true;
        }
    }
    return false;
}



int main() {
    int HP = 50;
    ifstream ifs;
    ifs.open("file.txt");

    // Line 1
    string line;
    getline(ifs, line);
    stringstream ssN1(line);
    int N1;
    ssN1 >> N1;

    for (int i = 0; i < N1; i++) {
        string lineFo;
        getline(ifs, lineFo);
        stringstream ssFo(lineFo);
        string N;
        ssFo >> N;
        int len = N.length();
        string s1="merlin";
        string s2="Merlin";
        size_t t1 = N.find(s1);
        size_t t2 = N.find(s2);
        if ( (t1 != string::npos) || (t2!= string::npos)){
            HP +=3;
        }else if(len >=6){
            HP +=2;
        }
    }
    cout<<HP;
     return 0;
}