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
using namespace std;
COORD coord= {0,0};
void gotoxy(int x,int y);
void gotoxy(int x,int y)//function to set the cursor position
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int wrong=0;
int timer = 0;
void sett();//sets time limit for playing game
int t=30;
int c=0;
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
    float count=0,p=0;
    bool input = false;
    string word,userword;
    int score=0;
    clock_t begin;
    int time_spent,speed;

    int r,letter,ch;

    srand(time(NULL)) ; //initilizes random function and seed with time
    x=2;
    pos;
    //setcolor(12);

        begin=clock();

    while(1)
    {

            time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;

            if(time_spent>=t)
                break;
        if(input == false)
        {
            pos;
             gotoxy(20,8);
            printf("....Type the following character....");
            gotoxy(36,11) ;
            word = big[rand()%len];
            cout << word << endl;
            input = true;

        }
        else
        {
            pos;

            cin >> userword;
           // system("cls");
            if(word == userword)
            {
                cout << "Matched\n";

            }
           input =false;

        }
        //current_time = time();

    }
    return (count/p)*100;
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
     random_word(big);
    cout<<endl;


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

void sett()  //set time limit
{
    int ch;
    system("cls");
    //rectangle(0,0,70,15);
    //setcolor(11);
    x=5;
    pos;
    printf("Set the time limit for game in minute::");
    pos;
    ln
    pos;
    printf("press 0 for half minute") ;//pos;
    printf("press 1 for 1 minute");// pos;
    printf("press 2 for 2 minute");//pos;
    scanf("%d",&ch);
    switch(ch)
    {
    case 0:
        t=30;
        break;
    case 1:
        t=60;
        break;
    case 2:
        t=120;
        break;
    default:
        main();
    }
}
