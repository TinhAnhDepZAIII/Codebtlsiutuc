#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

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


int calcS1(int n1) {
    
    int sum = 0;
    for (int i = 99; n1>0; n1--, i -= 2) {
        sum += i;
    }
    return sum;
}
int secondMaxInSequence(int *newNumber)
{
    int secondMaxx = -1;
    int second_pos = 0;
    if ((newNumber[0] > newNumber[1] && newNumber[0] < newNumber[2]) ||
        (newNumber[0] < newNumber[1] && newNumber[0] > newNumber[2]))
    {
        secondMaxx = newNumber[0];
    }

    else if ((newNumber[1] > newNumber[0] && newNumber[1] < newNumber[2]) ||
        (newNumber[1] < newNumber[0] && newNumber[1] > newNumber[2]))
    {
        secondMaxx = newNumber[1];
        second_pos = 1;
    }

    else if ((newNumber[2] > newNumber[0] && newNumber[2] < newNumber[1]) ||
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
bool checkMushGosh(string s)
{
    if (s[0] == '1' && s[1] == '3')
    {
        return true;
    }
    return false;
}

void currentLevel(int &a, int b)
{
    a = b;
}

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue)
{
    cout << "HP=" << HP
         << ", level=" << level
         << ", remedy=" << remedy
         << ", maidenkiss=" << maidenkiss
         << ", phoenixdown=" << phoenixdown
         << ", rescue=" << rescue << endl;
}

void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{

    fstream ifs;
    ifs.open("tc1_input", ios::in);
    //! line 1 🤣
    string line;
    getline(ifs, line);
    stringstream ss(line);
    ss >> HP >> level >> remedy >> maidenkiss >> phoenixdown;

    //?line 2
    string line2;
    getline(ifs, line2);
    stringstream ss2(line2);

    //! line 3
    string line3;
    getline(ifs, line3);
    stringstream ss3(line3);
    string pack1, pack2, pack3;
    getline(ss3, pack1, ',');
    getline(ss3, pack2, ',');
    getline(ss3, pack3);
    int MarkMerlin = 0;
    int MarkAclepius = 0;
    int MaxHP = HP;
    int tinySmall = 0;

    int turnFrog = 0;

    int CurrentLevell;
    string KoopaEvent;
    int i = 1;
    while (ss2 >> KoopaEvent)
    {
        if (KoopaEvent == "0" || MaxHP ==999)
        {
            rescue = 1;
            break;
        }
        else if( KoopaEvent =="99"){
            if ( (isPrime(HP) && level==8) || (level==10))
            {level =10;
            }
            else 
            {
                HP =-1;
                break;
            }
         }   
        else if (KoopaEvent == "17")
        {
            if (phoenixdown >= 0 && phoenixdown < 100)
            {
            }
            else
            {
                phoenixdown++;
            }
        }
        else if ((tinySmall != 0 || turnFrog != 0) && (i - tinySmall != 3 || i - turnFrog != 3))
        {
            if (KoopaEvent == "15")
            {
                HP = HP * 5;
                if (HP > MaxHP)
                {
                    HP = MaxHP;
                }
            }
            if (KoopaEvent == "16")
            {
                level = CurrentLevell;
            }
        }
        else if (KoopaEvent == "15")
        {
            if (remedy >= 0 && remedy < 100)
            {
            }
            else
            {
                remedy++;
            }
        }
        else if (KoopaEvent == "16")
        {
            if (maidenkiss >= 0 && maidenkiss < 100)
            {
            }
            else
            {
                maidenkiss++;
            }
        }

        else if (KoopaEvent == "1" || KoopaEvent == "2" || KoopaEvent == "3" || KoopaEvent == "4" || KoopaEvent == "5")
        {

            int b = i % 10;
            int levelO = i > 6 ? (b > 5 ? b : 5) : b;
            if (level > levelO)
            {
                if (level == 10)
                {
                }
                else
                {
                    level++;
                }
            }
            else if (level == levelO)
            {
            }
            else
            {
                int damage = levelO * (KoopaEvent == "1" ? 1 : (KoopaEvent == "2" ? 1.5 : (KoopaEvent == "3" ? 4.5 : (KoopaEvent == "4" ? 7.5 : 9.5)))) * 10;
                HP = HP - damage;

                if (HP <= 0 && phoenixdown == 0)
                {
                    break;
                }
                else if (HP <= 0 && (i - tinySmall != 3) && phoenixdown != 0 && tinySmall != 0)
                {
                    phoenixdown--;
                    HP = MaxHP;
                    tinySmall = 0;
                }
                else if (phoenixdown != 0)
                {
                    phoenixdown -= 1;
                    HP = MaxHP;
                }
            }
        }
        else if (KoopaEvent == "6" && ((i - tinySmall != 3 || i - turnFrog != 3) || (tinySmall == 0 || tinySmall == 0)))
        {
            tinySmall = i;

            int b = i % 10;
            int levelO = i > 6 ? (b > 5 ? b : 5) : b;
            if (level > levelO)
            {
                if (level == 10)
                {
                }
                else
                {
                    level += 2;
                }
            }
            else if (level == levelO)
            {
            }
            else
            {

                if (HP <= 5)
                {
                    HP = 1;
                }
                else
                {
                    HP = HP / 5;
                }

                if (remedy >= 1)
                {
                    HP = HP * 5;
                    remedy--;
                    if (HP > MaxHP)
                    {
                        HP = MaxHP;
                    }
                }
            }
        }
        else if (KoopaEvent == "7" && ((i - tinySmall != 3 || i - turnFrog != 3) || (tinySmall == 0 || turnFrog == 0)))
        {
            turnFrog = i;

            int b = i % 10;
            int levelO = i > 6 ? (b > 5 ? b : 5) : b;
            if (level > levelO)
            {
                if (level == 10 || level == 9 || level == 8)
                {
                }
                else
                {
                    level += 2;
                }
            }
            else if (level == levelO)
            {
            }
            else
            {
                if (maidenkiss != 0)
                {
                    maidenkiss--;
                }
                else
                {
                    currentLevel(CurrentLevell, level);
                    level = 1;
                }
            }
        }
        else if (checkMushGosh(KoopaEvent) || KoopaEvent == "18" || KoopaEvent == "19")
        {
            ifstream ifss;
            

            if (checkMushGosh(KoopaEvent))
            {
                

                int len = KoopaEvent.length();
                string num = ExtractMush(KoopaEvent, len);
                int lenNum = num.length();
                for (int i = 0; i < lenNum; i++)
                {
                    int digit = num[i] - '0';
                    int numm = numElementss(pack1);
                    int *N = new int[numm];
                    N = ExtractNumMush(pack1);

                    if (digit == 1)
                    {
                        int results = sumMinMaxPosition(N, numm);
                        HP = HP - results;
                    }
                    if (digit == 2)
                    {
                        int summit_pos = MaxPosInSequence(N, numm);
                        int summit_value = MaxValueInSequence(N, numm);
                        HP = HP - (summit_pos + summit_value);
                    }
                    if (digit == 3)
                    {
                        int results = ModifiedSequence(N, numm);
                        HP = HP - results;
                    }
                    if (digit == 4)
                    {
                        int *N41 = new int[3];
                        N41 = ModifiedSequence2(N, 3);
                        int results = secondMaxInSequence(N41);
                        HP = HP - results;
                    }
                }
            }
            else if ( KoopaEvent == "19" && MarkAclepius != 1)
            {
                ifstream ifs;
                ifs.open(pack2, ios::in);
                int MarkCount = 0;

                //! line 1
                string line1;
                getline(ifs, line1);
                stringstream ss1(line1);
                int N1;
                ss1 >> N1;

                //! line 2
                string line2;
                getline(ifs, line2);
                stringstream ss2(line2);
                int N2;
                ss2 >> N2;

                for (int i = 0; i < N1; i++)
                {
                    string lineFollowing;
                    getline(ifs, lineFollowing);
                    stringstream ssFollow(lineFollowing);
                    int NN;
                    while (ssFollow >> NN)
                    {
                        if (NN == 16 && MarkCount != 3)
                        {
                            remedy++;
                            MarkCount++;
                        }
                        else if (NN == 17 && MarkCount != 3)
                        {
                            maidenkiss++;
                            MarkCount++;
                        }
                        else if (NN == 18 && MarkCount != 3)
                        {
                            phoenixdown++;
                            MarkCount++;
                        }
                    }
                }
                MarkAclepius++;
            }
            else if ( KoopaEvent == "18" && MarkMerlin != 1)
            {
                ifstream ifs;
                ifs.open(pack3);

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
                    if ( len >=6){
                        if ( merlinn != string::npos || Merlinn != string::npos){
                            HP +=3;
                            if ( HP > MaxHP){
                                HP = MaxHP;
                            }
                        }
                        else 
                        {
                            HP += 2;
                            if ( HP > MaxHP){
                                HP = MaxHP;
                            }
                        }
                    }
                }
                MarkMerlin =1;                      
        }
        else if (KoopaEvent =="11"){
            int n1=((level + phoenixdown)%5+1)*3;
            int s1 = calcS1(n1);
            HP += s1%100;
            while (!isPrime(HP)){
                HP++;
            }
        }
        else if ( KoopaEvent =="12"){
            HP = updateHP(HP);
            if( HP >MaxHP){
                HP = MaxHP;
            }
        }

        i++;

        if (turnFrog != 0 && i - turnFrog - 1 == 3)
        {
            level = CurrentLevell;
            CurrentLevell = 0;
            turnFrog = 0;
        }
        if (tinySmall != 0 && i - tinySmall - 1 == 3)
        {
            if (HP == MaxHP)
            {
            }
            else
            {
                HP = HP * 5;
                tinySmall = 0;
            }
        }
    }

    if (HP > 0)
    {
        rescue = 1;
    }
    else
    {
        rescue = 0;
    }
    
    }

    display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
}

int main(int argc, char **argv)
{
    string file_input("tc1_input");

    int HP, level, remedy, maidenkiss, phoenixdown, rescue;
    adventureToKoopa(file_input, HP, level, remedy, maidenkiss, phoenixdown, rescue);

    return 0;
}



