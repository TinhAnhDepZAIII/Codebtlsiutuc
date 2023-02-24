#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>


// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to calculate s1
int calcS1(int n1) {
    
    int sum = 0;
    for (int i = 99; n1>0; n1--, i -= 2) {
        sum += i;
    }
    return sum;
}

int main() {
    int level = 2; // Replace with actual level
    int phoenixdown = 2; // Replace with actual number of phoenix downs
    int HP = 80; // Replace with actual current HP
   

    int n1 = ((level + phoenixdown) % 5 + 1) * 3;
    int s1 = calcS1(n1);
    std::cout<<s1<< std::endl;
    HP += s1 % 100;
    std::cout<<HP<<'\n';

    while (!isPrime(HP)) {
        HP++;
    }

    

    std::cout << "New HP: " << HP << std::endl;

    return 0;
}