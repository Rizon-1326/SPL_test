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
static int x=1;
#define pos gotoxy(30,x++)
#define ln  printf(".......................");

using namespace std;
COORD coord= {0,0};
void gotoxy(int x,int y);
void gotoxy(int x,int y)//function to set the cursor position
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void setcolor(int ForgC) //function to change setcolor
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

int timer = 0;
void sett();
void starttyping();
void English();
void Bangla();
void getscore(int accuracy,int speed,int level);
void scorecard();
void help();
void About_me();
string name;
int t=10;
int c=0;

/*void console_print(string pin)
{
    int run=pin.size();
    char check[run];

    for(int i=0; i<run; i++)
    {
        if(pin[i]==check[i])
            continue;
        else
        {
            //wrong++;
            break;
        }

    }
}*/

float random_word(vector <string> big,int level)
{
    int words=0,rigt=0,wrong=0,accuracy,speed;
    int len = big.size();
    float count=0,p=0;
    bool input = false;
    string word,userword;
    int score=0;
    clock_t begin;
    int time_spent;

    int r,letter,ch;

    srand(time(NULL)) ;
    x=2;
    // pos;
    //setcolor(12);

    begin=clock();

    while(1)
    {

        time_spent=(int)(clock()-begin)/CLOCKS_PER_SEC;

        if(time_spent>=t)
            break;
        if(input == false)
        {

            gotoxy(20,3);
            cout<<"....Type the following character...."<<endl;
            gotoxy(36,5) ;
            word = big[rand()%len];
            setcolor(10);
            cout << word << endl;
            words++;
            input = true;

        }
        else
        {
            // pos;
            setcolor(12);
            gotoxy(36,5);
            cin >> userword;
            system("cls");
            if(word == userword)
            {
                gotoxy(31,7);
                ln;
                cout<<endl;
                gotoxy(36,8);
                rigt++;
                cout << "Matched\n";

            }
            else
            {
                wrong++;
                 gotoxy(36,8);
                 cout << "Unmatched\n";
            }
            input =false;

        }
    }
    accuracy=(rigt*100)/words;
    speed=(words*60)/t;
    cout<<words<<endl;
    cout<<"Accuracy->"<<accuracy<<endl;
    cout<<"Speed->"<<speed<<"wpm"<<endl;

    getscore(accuracy,speed,level);

}
void read_word_by_word(string filename,int level)
{
    system("cls");
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
    random_word(big,level);
    cout<<endl;


}

int main()
{
    time_t t;
    time(&t);
    printf("%s",ctime(&t));
    cout<<"Welcome to typing test"<<endl;
    int x=1;
    setcolor(13) ;
    pos;
    ln pos;
    if(c==0)
    {
        cout<<"Enter player's name::"<<endl;
        gotoxy(30,4);
        cin>>name;
    }
    c++;
    system("cls");
    pos;
    ln pos;
    gotoxy(30,4);
    cout<<"#..MAIN MENU..#"<<endl;
    pos;
    ln
    pos;
    cout<<"1.startgame"<<endl;
    pos;
    cout<<"2.scorecard"<<endl;
    pos;
    cout<<"3.getscore"<<endl;
    pos;
    cout<<"4.Set the time limit::"<<endl;
    pos;
    cout<<"5.Help"<<endl;
    pos;
    cout<<"6.About me"<<endl;
    pos;
    cout<<"0.exit"<<endl;
    pos;
    cout<<"Enter your choice::"<<endl;
    int ch2;
    gotoxy(30,15);
    cin>>ch2;
    pos;
    switch(ch2)
    {
    case 1:
        starttyping();
        break;
    case 2:
        scorecard();
        break;
     case 3:
       int getscore(int accuracy,int speed,int level);
        break;
    case 4:
        sett();
        main();
    case 5:
        help();
        break;
    case 6:
        About_me();
        break;
    case 0:
        system("cls");
        gotoxy(17,10);
        cout<<"#This project is created by Khandakar Mehedi Hasan#"<<endl;
        //delay(1000);
        exit(1);
    default:
        main();
    }

    system("cls");

    // read_word_by_word(name);
}

void starttyping()
{
    system("cls");
    gotoxy(30,03);
    cout<<"Choice Language"<<endl;
    gotoxy(30,04);
    cout<<"1.English"<<endl;
    gotoxy(30,05);
    cout<<"2.Bangla"<<endl;
    gotoxy(30,06);
    cout<<"Enter your choice"<<endl;
    int ch;
    gotoxy(30,07);
    cin>>ch;
    switch(ch)
    {
    case 1:
        English();
    case 2:
        Bangla();
    }
}
void English()
{
    system("cls");
    gotoxy(30,03);
    cout << "Choice difficulty level "<<endl;
    pos;
    gotoxy(30,04);
    cout<<"1.Easy"<<endl;
    gotoxy(30,05);
    cout<<"2.Midium"<<endl;
    gotoxy(30,06);
    cout<<"3.Hard"<<endl;
    gotoxy(30,07);
    cout<<"Enter your choice"<<endl;
    int ch3;
    gotoxy(30,8);
    cin>>ch3;
    switch(ch3)
    {
    case 1:
    {
        read_word_by_word("example.txt",ch3);
        break;
    }
    case 2:
    {
        read_word_by_word("example2.txt",ch3);
        break;
    }
    case 3:
    {
        read_word_by_word("example3.txt",ch3);
        break;
    }
    }
}

void Bangla()
{
    cout << "Choice difficulty level "<<endl;
    pos;
    cout<<"1.Easy"<<endl;
    cout<<"2.Medium"<<endl;
    cout<<"3.Hard"<<endl;
    cout<<"Enter your choice"<<endl;
    int ch4;
    cin>>ch4;
    switch(ch4)
    {
    case 1:
    {
        read_word_by_word("b_example.txt",ch4);
        break;
    }
    case 2:
    {
        read_word_by_word("b_example2.txt",ch4);
        break;
    }
    case 3:
    {
        read_word_by_word("b_example3.txt",ch4);
        break;
    }
    }
}

void sett()  //set time limit
{
    int ch6;
    system("cls");
    setcolor(11);
    x=5;
    // pos;
    cout<<"Set the time limit for game in minute::"<<endl;
    //pos;
    ln
    //pos;
    cout<<"press 0 for half minute"<<endl;
   cout<<"press 1 for 1 minute"<<endl;
    cout<<"press 2 for 2 minute"<<endl;

    cin>>ch6;
    switch(ch6)
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

void getscore(int accuracy,int speed,int level)
{
    FILE *fp;
    fp=fopen("file.txt","a");
    pos;
    if(fp==NULL)
        printf("error in opening file");
    fprintf(fp,"\nname=%s   accuracy=%d    speed=%d    level=%d",name,accuracy,speed,level);
    fclose(fp);
    pos;
    printf("scorecard updated");
}


void scorecard()
{
    int ch;
    FILE *fp;
    system("cls");
    x=3;

    printf("\t\t\t....The scores are...\n");

    fp=fopen("file.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {
       cout<<ch;
    }
    main();
}

void help()
{
    system("cls");
    //rectangle(0,0,70,15);
    gotoxy(7,5);
    setcolor(6);

    cout<<"#......Rules of the Game......#"<<endl;
    gotoxy(7,6);
    cout<<"=>Enter your name as player name"<<endl;
    gotoxy(7,7);
    cout<<"=>Set the time limit under option 3 in main menu(default limit is 30 sec)"<<endl;
    gotoxy(7,8);
    cout<<"=>select the level and get started :"<<endl;
    gotoxy(7,9);
    cout<<"=>Characters are displayed and you have to type them as fast as you can.."<<endl;
    gotoxy(7,10);
    cout<<"=>Avoid incorrect typing otherwise game will be over.."<<endl;
    main();
}
void About_me()
{
    system("cls");
    gotoxy(7,7);
    printf("Hello everyone i am Khandakar Mehedi Hasan ,BSSE-13\N");
    printf(".I think it would be better....thanks...");
    main();
}


