#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

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

    ifstream ifs(file_input);
    ifs >> HP >> level >> remedy >> maidenkiss >> phoenixdown;

    int MaxHP = HP;

    int tinySmall = 0;

    int turnFrog = 0;
    
    int CurrentLevell;
    string KoopaEvent;
    int i = 1;
    while (ifs >> KoopaEvent)
    {
        if (KoopaEvent == "0")
        {
            rescue = 1;
            break;
        }
        if (KoopaEvent == "17")
        {
            phoenixdown++;
        }
        if (tinySmall != 0 && (i - tinySmall != 3 || i - turnFrog != 3))
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

        if (KoopaEvent == "1" || KoopaEvent == "2" || KoopaEvent == "3" || KoopaEvent == "4" || KoopaEvent == "5")
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
                int damage = levelO * (KoopaEvent == "1" ? 1 : (KoopaEvent == "2" ? 1.5 : (KoopaEvent == "3" ? 4.5 : (KoopaEvent == "4" ? 7.5 : 8.5)))) * 10;
                HP = HP - damage;

                if (HP <= 0 && phoenixdown == 0)
                {
                    break;
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
            if (HP < 0 && (i - tinySmall != 3) && phoenixdown != 0)
            {
                phoenixdown--;
                HP = MaxHP;
                tinySmall = -1;
            }

            cout << HP << endl;
        }
        else if (KoopaEvent == "7" && ((i - tinySmall != 3 || i - turnFrog != 3) || (tinySmall == 0 || tinySmall == 0)))
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

            cout << level << endl;
        }
        i++;

        cout << tinySmall << endl;
        cout << turnFrog << endl;
        cout << i << endl;
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

    cout << tinySmall << endl;
    cout << i << endl;

    if (HP > 0)
    {
        rescue = 1;
    }
    else
    {
        rescue = 0;
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
