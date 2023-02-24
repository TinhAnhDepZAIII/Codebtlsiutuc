#include <iostream>
using namespace std;

int nearestFibonacci(int n){
    int a =0, b=1,c;
    while (c<n){
        c= a+b;
        a=b;
        b=c;
    }

    if ( n ==b){
        return n;
    }else if ( abs(n-a) < abs(n-b)){
        return a;
    }else {return b;}
}

int updateHP (int hp){

    if ( hp >1){
        int hpUpdated = nearestFibonacci(hp);
        return hpUpdated;
    }else{ return hp;}
}

int main(){
    int hp =10;
    hp = updateHP(hp);
    cout<<hp;

}