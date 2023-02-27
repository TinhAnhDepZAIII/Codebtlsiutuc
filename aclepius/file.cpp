#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    int remedy=98;
    int phoenixdown =1;
    int maidenkiss=1;

    
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
    int CountPotion=0;

    for ( int i=0; i<N1; i++){
        string lineFollowing;
        getline(ifs, lineFollowing);
        stringstream ssFollow(lineFollowing);
        int NN;
        
        while(ssFollow >> NN){
            
            if( NN==16 && CountPotion <3 && remedy<99){
                remedy ++;
                CountPotion++;
                
            }
            else if(NN==17 && CountPotion <3 && maidenkiss <99){
                maidenkiss ++;
                CountPotion++;
               

            } else if ( NN==18 && CountPotion <3 &&phoenixdown<99){
                phoenixdown++;
                CountPotion++;
               

            }
           
        }
         CountPotion =0;
    }
    cout<<remedy<<maidenkiss<<phoenixdown;
    ifs.close();



return 0;
    
}