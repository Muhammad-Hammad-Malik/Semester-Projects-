#include <iostream>
using namespace std;
int userdecision(char a[][3],int rows, int count);
void tabdisp(char a[][3],int rows);
int condcheck(char a[][3],int rows);
int main()
{
    char a[3][3];
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            a[x][y]='*';
        }
        
    }
    int inputcheck=0;
    int endcheck=0;
    for(int xyz=1;xyz<=9;xyz++)
    {
        if(xyz%2!=0)
        {cout<<endl<<"              FIRST USER'S TURN "<<endl;}
        if(xyz%2==0)
        {cout<<endl<<"              SECOND USER'S TURN"<<endl;}
        tabdisp(a,3);
        inputcheck=userdecision(a,3,xyz);
        if(inputcheck==1)
        {
            xyz--;
            system("cls");
            cout<<"invalid input , TRY AGAIN !!";
            continue;
        }
        system("cls");
        endcheck=condcheck(a,3);
        if(endcheck==1)
       {cout<<"user 1 has won the game";
       return 0;}
        if(endcheck==2)
        {cout<<"user 2 has won the game";
        return 0;} 
       
    }
    
        cout<<"the game resulted in a draw";
    return 0;
}
void tabdisp(char a[][3],int rows)
{
    cout<<" _________________________"<<endl;
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            cout<<"|______";
            if(a[x][y]=='*')
               { cout<<" ";}
            else
                cout<<a[x][y];
            cout<<"|";    

        }
        cout<<endl;
    }
}
int userdecision(char a[][3],int rows,int count)
{
    int row=0,col=0;
    char marker;
    cout<<"enter the row position of your mark";
    cin>>row;
    cout<<"enter the column position of your mark";
    cin>>col;
    if(row<1||row>4||col<1||col>4)
    {
        return 1;
    }
    if(count%2!=0)
        marker='X';
    if(count%2==0)
        marker='O';
        if(a[row-1][col-1]=='*')
            {a[row-1][col-1]=marker;
            return 0;}
        else
            {return 1;}
}
int condcheck(char a[][3],int rows)
{
    if(a[0][2]=='O'&&a[1][2]=='O'&&a[2][2]=='O')
        return 1;
    if(a[0][0]=='O'&&a[0][1]=='O'&&a[0][2]=='O')
        return 1;
    if(a[0][1]=='O'&&a[1][1]=='O'&&a[2][1]=='O')
        return 1;
    if(a[0][0]=='O'&&a[1][0]=='O'&&a[2][0]=='O')
        return 1;
    if(a[1][0]=='O'&&a[1][1]=='O'&&a[1][2]=='O')
        return 1;
    if(a[2][0]=='O'&&a[2][1]=='O'&&a[2][2]=='O')
        return 1;
    if(a[0][0]=='O'&&a[1][1]=='O'&&a[2][2]=='O')
        return 1;
    if(a[0][2]=='O'&&a[1][1]=='O'&&a[2][0]=='O')
        return 1;
     if(a[0][2]=='X'&&a[1][2]=='X'&&a[2][2]=='X')
        return 2;
    if(a[0][0]=='X'&&a[0][1]=='X'&&a[0][2]=='X')
        return 2;
    if(a[0][1]=='X'&&a[1][1]=='X'&&a[2][1]=='X')
        return 2;
    if(a[0][0]=='X'&&a[1][0]=='X'&&a[2][0]=='X')
        return 2;
    if(a[1][0]=='X'&&a[1][1]=='X'&&a[1][2]=='X')
        return 2;
    if(a[2][0]=='X'&&a[2][1]=='X'&&a[2][2]=='X')
        return 2;
    if(a[0][0]=='X'&&a[1][1]=='X'&&a[2][2]=='X')
        return 2;
    if(a[0][2]=='X'&&a[1][1]=='X'&&a[2][0]=='X')
        return 2;
   else
   return 0;
}

