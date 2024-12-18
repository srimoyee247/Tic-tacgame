#include<iostream>
#include<conio.h>
using namespace std;
int ch;
char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int r,c;
int m;
void disp()
{
   cout<<"\n\nplayer 1 [x]\n";
    cout<<"player 2 [o]\n\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<a[0][0]<<"  |  "<<a[0][1]<<"  |  "<<a[0][2]<<"  \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<a[1][0]<<"  |  "<<a[1][1]<<"  |  "<<a[1][2]<<"  \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<a[2][0]<<"  |  "<<a[2][1]<<"  |  "<<a[2][2]<<"  \n";
    cout<<"\t\t     |     |     \n"; 
}
void player()
{
   if (turn == 'X')
    {
    cout<<"player 1 turn[X]=";
    cin>>ch;
     }
    else if (turn == 'O')
    {
    cout<<"player 2 turn[O]=";
    cin>>ch;
     }
    switch(ch)
    {
    case 1:
         r=0;
         c=0;
        break;
    case 2: 
        r=0;c=1;
        break;
    case 3: 
        r=0;c=2;
        break;
    case 4:
         r=1;c=0;
        break;
    case 5:
         r=1;c=1;
        break;
    case 6:
         r=1;c=2;
        break;
    case 7:
         r=2;c=0;
        break;
    case 8:
         r=2;c=1;
        break;
    case 9:
         r=2;c=2;
        break;
        default:
        cout<<"Invalid choice";
    }
    if (turn=='X' && a[r][c]!='X' && a[r][c]!='O')
    {
     a[r][c]='X';
        turn='O';
    }
    else if (turn=='O'&& a[r][c]!='X' && a[r][c]!='O')
    {
     a[r][c]='O';
        turn='X';
    }
    else
     cout<<"\t !!!!!!__BOX ALREADY FILLD__!!!!!! \n \t ----[PLEASE TRY AGIN]----\n";
    disp();
}

int check()
{
   for(int i=0;i<3;i++)
    {
        if (a[i][0]==a[i][1]&&a[i][0]==a[i][2] || a[0][i]==a[1][i]&&a[0][i]==a[2][i] || a[0][0]==a[1][1]&&a[0][0]==a[2][2] || a[0][2]==a[1][1]&&a[0][2]==a[2][0])
        return 0;
    }
    
    for(int i=0;i<3;i++)
    {
    for(int j=0;j<3;j++)
        {
            if(a[i][j]!='X'&&a[i][j]!='O')
            return 1;
        }
    }
    
    m=1;
    return 0;
}
int main ()
{   
    disp();
    while(check())
    {
        player();
        check();
    }
        
    if(turn=='X'&&m==0)
    {
    cout<<"\n\n\n\t\tPLAYER 2 [O] WIN THE GAME\n\n\t---<<<<<<]• CONGRATULATION •[>>>>>---";
    }
    else if (turn=='O' && m==0)
    {
    cout<<"\n\n\n\t\tPLAYER 1 [X] WIN THE GAME\n\n\t---<<<<<<]• CONGRATULATION •[>>>>>---";
    }
    else 
     cout<<"\n\n\t   ~~~~~GAME DRAW~~~~~\n\n";
    getch();
    return 0;
}
