#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    int remedy=1;
    int phoenixdown =1;
    int maidenkiss=1;

    int MarkRemedy= 0;
    int MarkPhoenix=0;
    int MarkMaidenKiss=0;

    ifstream ifs;
    ifs.open("file.txt", ios::in);

    //!line 1
    string line1;
    getline(ifs,line1);
    stringstream ss1(line1);
    int N1;
    ss1>>N1;
    //!line 2
    string line2;
    getline(ifs,line2);
    stringstream ss2(line2);
    int N2;
    ss2>>N2;


    for ( int i=0; i<N1; i++){
        string lineFollowing;
        getline(ifs, lineFollowing);
        stringstream ssFollow(lineFollowing);
        int NN;
        while(ssFollow >> NN){
            if( NN==16 && MarkRemedy !=1){
                remedy ++;
                MarkRemedy=1;
                
            }
            else if(NN==17 && MarkMaidenKiss !=1){
                maidenkiss ++;
                MarkMaidenKiss=1;

            } else if ( NN==18 && MarkPhoenix !=1){
                phoenixdown++;
                MarkPhoenix =1;

            }
        }
    }
    cout<<remedy<<maidenkiss<<phoenixdown;
    ifs.close();



return 0;
    
}