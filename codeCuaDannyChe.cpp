#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
void readFile(string file_input,int & HP, int & level, int & remedy,int & maidenkiss, int & phoenixdown, int & rescue);
void checkStatus(int rescue);
int isPrime(int &HP);
int isPrime1(int &maxHP);
int checkfibonacci(int &HP);

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}
int isPrime(int &HP)
{
    // Corner case
    if (HP <= 1){
        return 0;
      }
    // Check from 2 to n-1
    for (int i = 2; i < HP; i++){
        if (HP % i == 0){
            return 0;
          }
      }
    return 1;
}
int isPrime1(int &maxHP)
{
    // Corner case
    if (maxHP <= 1){
        return 0;
      }
    // Check from 2 to n-1
    for (int i = 2; i < maxHP; i++){
        if (maxHP % i == 0){
            return 0;
          }
      }
    return 1;
}

int checkfibonacci(int &HP)
        {
            int a = 0;
            int b = 1;
            if (HP==a || HP==b) return 1;
            int c = a+b;
            while(c<=HP)
            {
                if(c == HP) return 1;
                a = b;
                b = c;
                c = a + b;
            }
            return 0;
        }
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    readFile(file_input, HP, level, remedy, maidenkiss, phoenixdown, rescue);
}

void readFile(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    // open input file
    rescue = -1;
    ifstream inputFile(file_input);

    // read first line of input file
    string inputLine;
    getline(inputFile, inputLine);

    // parse numbers from input line and match them with variables
    istringstream iss(inputLine);
    iss >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
    //display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
    // read second line of input file
    getline(inputFile, inputLine);

    //read third line of input file
    
    ifstream file;
    file.open(file_input);
    string x,y,z;
    getline(file,x);
    getline(file,y);
    getline(file,z);
    string rtr[3];
    int dm=0;
    z+=",";
    for(int i=0;i<z.length();i++){
        if(z[i]==44){
            dm++;
            continue;
        }
        rtr[dm]+=z[i];
    }
    file.close();

    // count the amount of event
    int count = 1;
    for (char c : inputLine) {
        if (isspace(c)) {
            count++;
        }
    }

    // parse numbers from second line and call event function for each number
    istringstream iss2(inputLine);
    int num, b, levelO;
    int maxLevel = 10;
    int eventVal = 0;
    int maxHP = HP;
    int tiny=0;
    int tinytime=0;
    int frogtime=0;
    int temp=0;
    int le=99;
    int n1;
    int s1=0;
    int count19=0;
    
//display(HP, level, remedy, maidenkiss, phoenixdown, rescue);

    while (iss2 >> num) 
    {
        ++eventVal;
        if (num == 0) { // Bowser đầu hàng và trả lại công chúa
            rescue = 1;
            //checkStatus(rescue);
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            break;
        } else if (num == 1) { // Gặp gấu MadBear
        
            if (tiny!=0){
                tinytime=tinytime-1;               
                }
            if (frogtime!=0){
                frogtime=frogtime-1;
            }else if (frogtime==0){
                    level=temp;
                }
            b = eventVal%10;
            levelO = eventVal > 6?(b > 5?b : 5) : b;
            if ((level > levelO) || (HP==999) || (isPrime1(maxHP)==1)){
                level++;
                level = min(level, maxLevel);
                if (eventVal == count) {
                            rescue = 1;
                            // checkStatus(rescue);
                        }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
            else if (level == levelO) {
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
            } else if (level < levelO) {
                float baseDamage = 1;
                int damage = baseDamage * levelO * 10;
                HP = HP - damage;
                if (tiny==1)
                {
                    if(tinytime==0 ||remedy!=0)
                    {
                    HP=HP*5;
                    }
                }
                if (HP <= 0) {
                    if (phoenixdown >= 1) {
                        tiny=0;
                        frogtime=0;
                        HP = maxHP;
                        phoenixdown -= 1;
                        if (eventVal == count) {
                            rescue = 1;
                            // checkStatus(rescue);
                        }
                    } else {
                        rescue = 0;
                        // checkStatus(rescue);
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        break;
                    }
                } else {
                    if (eventVal == count) {
                        rescue = 1;
                        // checkStatus(rescue);
                    }
                }
            
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);

            }
        } else if (num == 2) { // Gặp gấu Bandit
        
            if (tiny!=0){
                tinytime=tinytime-1;               
                }
            if (frogtime!=0){
                frogtime=frogtime-1;
            }else if (frogtime==0){
                    level=temp;
                }
            b = eventVal%10;
            levelO = eventVal > 6?(b > 5?b : 5) : b;
            if ((level > levelO) || (HP==999) || (isPrime1(maxHP)==1)) {
                level++;
                level = min(level, maxLevel);
                if (eventVal == count) {
                            rescue = 1;
                            // checkStatus(rescue);
                        }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
            else if (level == levelO) {
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
            } else if (level < levelO) {
                float baseDamage = 1.5;
                int damage = baseDamage * levelO * 10;
                HP = HP - damage;
                if (tiny==1)
                {
                    if(tinytime==0 ||remedy!=0)
                    {
                    HP=HP*5;
                    }
                }
                if (HP <= 0) {
                    if (phoenixdown >= 1) {
                        tiny=0;
                        frogtime=0;
                        HP = maxHP;
                        phoenixdown -= 1;
                        if (eventVal == count) {
                            rescue = 1;
                            // checkStatus(rescue);
                        }
                    } else {
                        rescue = 0;
                        // checkStatus(rescue);
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        break;
                    }
                } else {
                    if (eventVal == count) {
                        rescue = 1;
                        // checkStatus(rescue);
                    }
                }
            
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);

            }
        } else if (num == 3) { // Gặp gấu LordLupin
        
            if (tiny!=0){
                tinytime=tinytime-1;               
                }
            if (frogtime!=0){
                frogtime=frogtime-1;
            }else if (frogtime==0){
                    level=temp;
                }
            b = eventVal%10;
            levelO = eventVal > 6?(b > 5?b : 5) : b;
            if ((level > levelO) || (HP==999) || (isPrime1(maxHP)==1)) {
                level++;
                level = min(level, maxLevel);
                if (eventVal == count) {
                            rescue = 1;
                            // checkStatus(rescue);
                        }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
            else if (level == levelO) {
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
            } else if (level < levelO) {
                float baseDamage = 4.5;
                int damage = baseDamage * levelO * 10;
                HP = HP - damage;
                if (tiny==1)
                {
                    if(tinytime==0 ||remedy!=0)
                    {
                    HP=HP*5;
                    }
                }
                if (HP <= 0) {
                    if (phoenixdown >= 1) {
                        tiny=0;
                        frogtime=0;
                        HP = maxHP;
                        phoenixdown -= 1;
                        if (eventVal == count) {
                            rescue = 1;
                            // checkStatus(rescue);
                        }
                    } else {
                        rescue = 0;
                        // checkStatus(rescue);
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        break;
                    }
                } else {
                    if (eventVal == count) {
                        rescue = 1;
                        // checkStatus(rescue);
                    }
                }
            
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);

            }
        } else if (num == 4) { // Gặp Elf
        
            if (tiny!=0){
                tinytime=tinytime-1;               
                }
            if (frogtime!=0){
                frogtime=frogtime-1;
            }else if (frogtime==0){
                    level=temp;
                }
            b = eventVal%10;
            levelO = eventVal > 6?(b > 5?b : 5) : b;
            if ((level > levelO) || (HP==999) || (isPrime1(maxHP)==1)) {
                level++;
                level = min(level, maxLevel);
                if (eventVal == count) {
                            rescue = 1;
                            // checkStatus(rescue);
                        }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
            else if (level == levelO) {
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
            } else if (level < levelO) {
                float baseDamage = 7.5;
                int damage = baseDamage * levelO * 10;
                HP = HP - damage;
                if (tiny==1)
                {
                    if(tinytime==0 ||remedy!=0)
                    {
                    HP=HP*5;
                    }
                }
                if (HP <= 0) {
                    if (phoenixdown >= 1) {
                        tiny=0;
                        frogtime=0;
                        HP = maxHP;
                        phoenixdown -= 1;
                        if (eventVal == count) {
                            rescue = 1;
                            // checkStatus(rescue);
                        }
                    } else {
                        rescue = 0;
                        // checkStatus(rescue);
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        break;
                    }
                } else {
                    if (eventVal == count) {
                        rescue = 1;
                        // checkStatus(rescue);
                    }
                }
            
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);

            }
        }else if (num == 5) { // Gặp Troll
        
            if (tiny!=0){
                tinytime=tinytime-1;               
                }
            if (frogtime!=0){
                frogtime=frogtime-1;
            }else if (frogtime==0){
                    level=temp;
                }
            b = eventVal%10;
            levelO = eventVal > 6?(b > 5?b : 5) : b;
            if ((level > levelO) || (HP==999) || (isPrime1(maxHP)==1)) {
                level++;
                level = min(level, maxLevel);
                if (eventVal == count) {
                            rescue = 1;
                            // checkStatus(rescue);
                        }
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            }
            else if (level == levelO) {
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
            } else if (level < levelO) {
                float baseDamage = 9.5;
                int damage = baseDamage * levelO * 10;
                HP = HP - damage;
                if (tiny==1)
                {
                    if(tinytime==0 ||remedy!=0)
                    {
                    HP=HP*5;
                    }
                }
                if (HP <= 0) {
                    if (phoenixdown >= 1) {
                        tiny=0;
                        frogtime=0;
                        HP = maxHP;
                        phoenixdown -= 1;
                        if (eventVal == count) {
                            rescue = 1;
                            // checkStatus(rescue);
                        }
                    } else {
                        rescue = 0;
                        // checkStatus(rescue);
                        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                        break;
                    }
                } else {
                    if (eventVal == count) {
                        rescue = 1;
                        // checkStatus(rescue);
                    }
                }
            
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);

            }
        }else if (num==6){//Meet Shaman 
            
            if (frogtime!=0){
                frogtime=frogtime-1;
            }
            if (frogtime==0){
               level=temp;
            }
            if (eventVal == count) {
                rescue = 1;
                // checkStatus(rescue);
            }
            b = eventVal%10;
            levelO = eventVal > 6?(b > 5?b : 5) : b;
            if (level > levelO || (HP==999) || (isPrime1(maxHP)==1)) {
                level=level +2;
                level = min(level,maxLevel);
                display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
            } else if (level == levelO) {
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
            } else if (level < levelO) {
                if (remedy>=1){
                    remedy-=1;
                    tiny=0;
                }else {
                ++tiny;
                tinytime=3;
                if (HP<5) {
                    HP=1;
                    }else {
                    HP=HP/5;
                    }
                }
                
            } 
            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
        }else if (num==7){//Meet Vajsh   
        if (eventVal == count) {
                rescue = 1;
                // checkStatus(rescue);
            }
             if (tiny!=0){
                tinytime=tinytime-1;
                if (tinytime==0 && remedy!=0){
                    HP=HP*5;
                }
            }
            b = eventVal%10;
            levelO = eventVal > 6?(b > 5?b : 5) : b;
            if (level > levelO || (HP==999) || (isPrime1(maxHP)==1)) {
                level=level +2;
                level = min(level,maxLevel);
                display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
            } else if (level == levelO) {
                display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
                continue;
            } else if (level < levelO) {
              if (maidenkiss>=1){
                maidenkiss--;
                frogtime=0;
              }else{
                frogtime=3;
                level=temp;
                level=1;
              }
            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);  
    }
          }
          else if(num==11){
        if (eventVal == count) {
                        rescue = 1;
                        // checkStatus(rescue);
          }
        n1=((level+phoenixdown)%5+1)*3;
        for (int i=0;i<n1;i++){
          s1+=le;
          le-=2;
        }
        HP=HP+(s1%100);
        while (isPrime(HP)==0||isPrime(HP)==1){
          HP++;
          if(isPrime(HP)==1){
            break;
          }
        }
        HP=min(HP,maxHP);
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
          }
      else if(num==12){
        if (eventVal == count) {
                        rescue = 1;
                        // checkStatus(rescue);
          }
        if (HP>1){
          while (checkfibonacci(HP)==0){
            HP--;
            if(checkfibonacci(HP)==1){
              break;
            }
          }
        }
          
        display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
          
        
      }
      else if (num==15){
             if (eventVal == count) {
                            rescue = 1;}
            if (tiny==0){
                ++remedy;
                remedy=min(remedy,99);
            }else{//tiny==1
                tiny=0;
                tinytime=0;
                HP=HP*5;
            }display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
        }else if (num==16){
            if (eventVal == count) {
                            rescue = 1;}
            if (frogtime==0){
                ++maidenkiss;
                maidenkiss=min(maidenkiss,99);
            }else{//tiny==1
                frogtime=0;
                level=temp;
            }display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
        }else if (num==17){
            if (eventVal == count) {
                rescue = 1;}
                ++phoenixdown;
            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
        }else if (num==99){
            if (eventVal == count) {
                rescue = 1;}
            if ((HP==999)||(level==10)||((isPrime1(maxHP))&&(level>=8))){
                level=10;display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
            }else{
                rescue=0;display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
                break;
            }
        }else if (num==18){  //merlin
            file.open(rtr[2]);
            int xuat;
            file>>xuat;
            string nhap[100];
            for(int i=0;i<xuat;i++){
            file>>nhap[i];
            }
            file.close();
            char m[7]="merlin";
            

            for(int i=0;i<xuat;i++){
                int m2[6]{};
                string xet=nhap[i];
                for(int j=0;j<nhap[i].length();j++){
                     for(int k=0;k<6;k++){
                        if(m2[k]==0)
                        {
                            if(xet[j]==m[k] || xet[j]==m[k]-32)
                            {
                                m2[k]+=1;
                            }
                        }
                     }
                }
                
                int d=0,d2=0;
                for(int k=0;k<6;k++)
                {
                    if(m2[k]==1)
                        d+=1;
                }
                if(d==6){
                    HP+=2;

                   for(int k=0;k<nhap[i].length();k++){
                    d2=0;
                    if(xet[k]==m[0] || xet[k]==m[0]-32){
                        for(int l=1;l<6;l++)
                        {
                            if(xet[k+l]==m[l])
                            {
                                d2+=1;
                            }
                        }
                        }
                    if (d2==5)
                    {
                       HP+=1;
                       break; 
                    }
                        
                    
                   }
                   
                }
                HP=min(HP,maxHP);
            }
            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
        }
        else if (num==19){  //aclepius
            if(count19==0){
            count19+=1;
            file.open(rtr[1]);
            int xuat1,xuat2;
            file>>xuat1;
            file>>xuat2;
            int nhap[100][100];
            for(int i=0;i<xuat1;i++){
                for(int j=0;j<xuat2;j++){
            file>>nhap[i][j];
            }
            }
            file.close();
            for(int i=0;i<xuat1;i++){
                int dem=0;
                for (int j=0;j<xuat2;j++)
        {
                if(nhap[i][j]==16)
            {
                     remedy++;
                     remedy=min(remedy,99);
                     dem++;
                     if(dem==3) break;
            }
                else if(nhap[i][j]==17)
            {
                    maidenkiss++;
                    maidenkiss=min(maidenkiss,99);
                    dem++;
                    if(dem==3) break;
            }
                else if(nhap[i][j]==18)
            {
                    phoenixdown++;
                    phoenixdown=min(phoenixdown,99); 
                    dem++;
                    if(dem==3) break;
            }
            }
        }
            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
    }
        }
        else{ //mush_ghost
            if (eventVal == count) {
                        rescue = 1;
                        // checkStatus(rescue);
                    }
            int num_text=0;
            while(num>0)
            {
                int text=num%10;
                num_text=num_text*10+text;
                num/=10;
            }
            if(num_text%100==31)
            {
                num_text-=31;
                num_text/=100;
                file.open(rtr[0]);
                int xuat;
                file>>xuat;
                string phay;
                file>>phay;
                file.close();
                int nhap[100];
                nhap[0]=0;
                int tam=0;
                int am=0;
                for(int i=0;i<phay.length();i++)
                {
                    if(phay[i]==44)
                    {
                        if(am==1)
                        {
                            nhap[tam]=-nhap[tam];
                            am=0;
                        }
                        tam+=1;
                        nhap[tam]=0;
                        continue;
                    }
                    if(phay[i]==45)
                    {
                        am=1;
                        continue;
                    }
                    
                    int tam2=(int)phay[i];
                    nhap[tam]=nhap[tam]*10+tam2-48;//ascii to decimal
                }
                
                while(num_text>0)
                {
                    num=num_text%10;
                    num_text/=10;
                    if(num==1)
                    {
                        int mini=-1;
                        int maxi=-1;
                        int lon=nhap[0];
                        int nho=nhap[0];
                        for(int i=0;i<xuat;i++)
                        {
                            if(nhap[i]>lon){
                                lon=nhap[i];
                            } 
                            if(nhap[i]<nho){
                                nho=nhap[i];
                            }
                        }
                        for(int i=xuat-1;i>=0;i--)
                        {
                            if(mini==-1 && nhap[i]==nho)
                            {
                                mini=i;
                            }
                            if(maxi==-1 && nhap[i]==lon)
                            {
                                maxi=i;
                            }
                        }
                        HP=HP-(maxi+mini);
                    }
                    else if(num==2)
                    {
                        int lon=nhap[0];
                        int poslon;
                        for(int i=1;i<xuat;i++)
                        {
                            if(nhap[i]>lon)
                            {
                                lon=nhap[i];
                                poslon=i;
                            }
                        }

                        int fail=0;
                        for(int i=0;i<xuat;i++)
                        {
                            if(i<poslon && nhap[i]>nhap[i+1]) // left of extrema
                            {
                                fail+=1;
                                break;
                            }
                            if(i>=poslon && nhap[i]<nhap[i+1]) // right of extrema
                            {
                                fail+=1;
                                break;
                            }
                        }
                        if(fail==0)
                        {
                            HP=HP-lon-poslon;
                        }
                        else HP=HP-(-2-3);
                    }
                    else if(num==3)
                    {
                        int mini2=-1;
                        int maxi2=-1;
                        int nhap2[100];
                        for(int i=0;i<xuat;i++)
                        {
                            if(nhap[i]<0)
                                nhap2[i]=(17*(-nhap[i])+9)%257;
                            else nhap2[i]=(17*nhap[i]+9)%257;
                        }
                        int lon=nhap2[0];
                        int nho=nhap2[0];
                        for(int i=1;i<xuat;i++)
                        {
                            if(nhap2[i]>lon){
                                lon=nhap2[i];
                            } 
                            if(nhap2[i]<nho){
                                nho=nhap2[i];
                            }
                        }
                        for(int i=0;i<xuat;i++)
                        {
                            if(mini2==-1 && nhap2[i]==nho)
                            {
                                mini2=i;
                            }
                            if(maxi2==-1 && nhap2[i]==lon)
                            {
                                maxi2=i;
                            }
                        }
                        HP=HP-(mini2+maxi2);
                    }
                    else if(num==4)
                    {
                        int max2_3x=-5;
                        int max2_3i=-7;
                        int nhap2[100];
                        for(int i=0;i<3;i++)
                        {
                            if(nhap[i]<0)
                                nhap2[i]=(17*(-nhap[i])+9)%257;
                            else nhap2[i]=(17*nhap[i]+9)%257;
                        }
                        int lon=nhap2[0];
                        int lon2=0;
                        for(int i=0;i<3;i++)
                        {
                            if(nhap2[i]>lon)
                                lon=nhap2[i];
                            else if (nhap2[i]<lon && nhap2[i]>lon2)
                                lon2=nhap2[i];
                        }
                        for(int i=0;i<3;i++) //xet 3 so dau day
                        {
                            if(nhap2[i]==lon2)
                            {
                                max2_3x=lon2;
                                max2_3i=i;
                            }
                        }
                        HP=HP-(max2_3x+max2_3i);
                    }
                }
                
            }
            display(HP,level,remedy,maidenkiss,phoenixdown,rescue);
        }
    
    }  

    // close input file
    inputFile.close();
}


void checkStatus(int rescue) 
{
    if (rescue == 1) {
        cout << "Mission success.\n"; 
    } else if (rescue == 0) {
        cout << "Mission fail.\n";
    }
}

int main(int argc, char **argv)
{
    string file_input("tc1_input");
    int HP, level, remedy, maidenkiss, phoenixdown, rescue;
    adventureToKoopa(file_input, HP, level, remedy, maidenkiss, phoenixdown, rescue);
    return 0;
}   


