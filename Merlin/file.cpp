#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    int HP ;
    ifstream ifs;
    ifs.open("file.txt");

    //!Line 1
    string line;
    getline(ifs,line);
    stringstream ss(line);
    int N1;
    ss>>N1;

    for ( int i=0; i< N1; i++){
        string lineFo;
        getline(ifs,lineFo);
        stringstream ssFo(lineFo);
        string N;
        ss>>N;
        int len= N.length();
        string s1="merlin";
        string s2="Merlin";
        size_t merlinn=N.find(s1);
        size_t Merlinn=N.find(s2);

        if (merlinn != string::npos || Merlinn !=string::npos){
            
        }
    }
}