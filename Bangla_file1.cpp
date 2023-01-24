#include<iostream>
#include<fstream>
#include<string>
#include<math.h>
#include<ctime>
#include<vector>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<dos.h>
#include<stdlib.h>
//#include<graphics.h>
static int x=1;//used for x cursor co-ordinate
#define pos gotoxy(30,x++) /*for cursor movement*/
#define ln  printf(".......................");
//.......................................................................................................................................................................
COORD coord= {0,0};
void gotoxy(int x,int y);
void gotoxy(int x,int y)//function to set the cursor position
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
using namespace std;
int wrong=0;
int timer = 0;
void console_print(string pin)
{
    int run=pin.size();
    char check[run];

    for(int i=0; i<run; i++)
    {
        if(pin[i]==check[i])
            continue;
        else
        {
            wrong++;
            break;
        }

    }
}
float random_word(vector <string> big)
{
    int len = big.size();
    float t = 0,count=0,p=0;
    bool input = false;
    string word, userword;
    while(p<4)
    {
        if(input == false)
        {
            pos;
            word = big[rand()%len];
            cout << word << endl;
            input = true;
            p++;
           cout<<p;
        }
        else
        {
            pos;
            cin >> userword;
            system("cls");
            if(word == userword)
            {
                cout << "Matched\n";
                count++;
              //input = false;
            }

        input = false;
        }
        //current_time = time();

    } return (count/p)*100;
}
void read_word_by_word(string filename)
{
    fstream file;
    vector <string> big;
    string word;
    file.open(filename.c_str());
    while(file >> word)   //take word and print
    {
        big.push_back(word);
        //file.close();
    }
    //cout<<big;
    float k= random_word(big);
    cout<<endl;
    cout<<k;

}
int main()
{
    string name;
    time_t t;
	time(&t);
    printf("%s",ctime(&t));
   // cout<<"Welcome to ty
   int x=1;
   pos;
    cout << "Enter filename: ";
    pos;
    cin >> name;
    read_word_by_word(name);
}
