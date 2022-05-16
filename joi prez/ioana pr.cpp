#include <iostream>
#include <cmath>
#include<graphics.h>
#include<winbgim.h>
#define MAX 7
#define FUNDAL GREEN
using namespace std;
struct joc
{
    int tabla[MAX][MAX];
    char numeJucator[50];
    int level;
};


void initializare( int a[7][7])
{
    int i, j;
    for( i=0; i<=6; i++)
        for( j=0; j<=6; j++)
            a[i][j]=1;
    a[0][0]=2;
    a[0][1]=2;
    a[0][5]=2;
    a[0][6]=2;
    a[1][0]=2;
    a[1][1]=2;
    a[1][5]=2;
    a[1][6]=2;
    a[5][0]=2;
    a[5][1]=2;
    a[5][5]=2;
    a[5][6]=2;
    a[6][0]=2;
    a[6][1]=2;
    a[6][5]=2;
    a[6][6]=2;
    a[3][3]=0;


}
void afisare (int a[7][7] )
{
    for (int i=0; i<=6; i++)
    {
        for( int j=0; j<=6; j++)
            cout<<a[i][j]<<" "<<"|";
        cout<<endl;
    }
    cout<< endl;
}
void desenareTabla()
{
    for (int i=0; i<=7; i++)
        if(i==0 || i==1 ||i==6 || i==7)
            line(i*100, 200, i*100, 500);
        else
            line( i*100, 0, i*100, 700);
    for (int i=0; i<=7; i++)
        if(i==0 || i==1 ||i==6 || i==7)
            line(200, i*100, 500, i*100);
        else
            line( 0, i*100, 700, i*100);

}


void desenarePiese (int a[7][7])
{
    for(int i = 0; i < 7; i++)
    {
        for (int j = 0 ; j < 7; j++)
        {
            if (a[j][i] == 1)
            {
                setfillstyle(SOLID_FILL, WHITE);

                setcolor(WHITE);

                fillellipse(i*100+50, j*100+50, 20,20);
                circle(i*100+50, j*100+50, 20);
            }
            else
            {
                setfillstyle(SOLID_FILL, BLACK);

                setcolor(BLACK);

                fillellipse(i*100+50, j*100+50, 20,20);
                circle(i*100+50, j*100+50, 20);

            }
        }
    }
}
bool miscarePosibila(int a[7][7],int i, int j, char directie)
{
    if(directie == 'N')

        if((a[i][j]==1) && (a[i-2][j]==0) && (i-2 >= 0))

            return true;
        else
            return false;

    else if (directie == 'S')

        if((a[i][j]==1) &&(a[i+2][j] == 0) && ((i+2) <= 6) )

            return true;
        else
            return false;

    else if (directie == 'E')

        if((a[i][j]==1) &&(a[i][j+2] == 0) && ((j+2) <= 6) )

            return true;
        else
            return false;


    else if (directie == 'V')

        if((a[i][j]==1) &&(a[i][j-2] == 0) && ((j-2)>=0) )
            return true;
        else
            return false;

}
void mutare (int a[7][7], int i, int j, char directie)
{
    if (miscarePosibila(a, i, j, directie))
    {
        if(directie == 'N')
        {
            a[i-1][j] = 0;
            a[i-2][j] = 1;
        }
        else if (directie == 'S')
        {
            a[i+1][j] = 0;
            a[i+2][j] = 1;
        }
        else if (directie == 'E')
        {
            a[i][j+1] = 0;
            a[i][j+2] = 1;
        }
        else if (directie == 'V')
        {
            a[i][j-1] = 0;
            a[i][j-2] = 1;
        }
        a[i][j] = 0;
        afisare(a);
        desenarePiese(a);
    }
    else
        cout<<"Miscarea nu este posibila. Introduceti alta"<<endl;

}
bool miscareDublaPosibila(int a[7][7],int i, int j, char directie)
{
    if(directie == 'N')

        if((a[i][j]==1) && a[i-2][j]==0 && a[i-4][j]==0 && (i-4) >=0 )

            return true;
        else
            return false;

    else if (directie == 'S')

        if((a[i][j]==1) && a[i+2][j]==0 && a[i+4][j]==0 && (i+4)<=6)

            return true;
        else
            return false;

    else if (directie == 'E')

        if((a[i][j]==1) && a[i][j+2]==0 && a[i][j+4]==0 && (j+4)<=6)

            return true;
        else
            return false;


    else if (directie == 'V')

        if((a[i][j]==1) && a[i][j-2]==0 && a[i][j-4]==0 && (j-4)>=0)
            return true;
        else
            return false;

}

void mutareDubla(int a[7][7],int i, int j, char directie)
{
    if (miscarePosibila(a, i, j, directie))
    {
        if(directie == 'N' )
        {
            a[i-1][j]=0;
            a[i-3][j]=0;
            a[i-4][j]=1;
            a[i][j]=0;
        }
        else if (directie == 'S' )
        {
            a[i+1][j]=0;
            a[i+3][j]=0;
            a[i+4][j]=1;
            a[i][j]=0;
        }
        else if (directie == 'E' )
        {
            a[i][j+1]=0;
            a[i][j+3]=0;
            a[i][j+4]=1;
            a[i][j]=0;

        }
        else if (directie == 'V' )
        {
            a[i][j-1]=0;
            a[i][j-3]=0;
            a[i][j-4]=1;
            a[i][j]=0;
        }
        afisare(a);
        desenarePiese(a);
    }
}

void utilizareMouse(int a[7][7])
{

    int x=0, y=0, x2=0, y2=0;
    bool click;
    do
    {
        click=false;
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            click=true;
             Beep( 1000, 100);
            getmouseclick(WM_LBUTTONDOWN,x, y);
            x=x/100;
            y=y/100;
        }
    }
    while (!click);
    do
    {
        click=false;
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            click=true;
            Beep(1500, 200);
            getmouseclick(WM_LBUTTONDOWN, x2, y2);
            x2=x2/100;
            y2=y2/100;
        }
    }
    while (!click);
    if(x==x2 && y-y2==2 && miscarePosibila(a, y,x, 'N'))
                mutare(a,y, x, 'N');
            else if(x==x2 && y-y2==-2 && miscarePosibila(a, y, x, 'S'))
                mutare(a,y, x, 'S');
            else if(y==y2 && x-x2==2 && miscarePosibila(a, y, x, 'V')  )
                mutare(a, y, x, 'V');
            else if(y==y2 && x-x2==-2 && miscarePosibila(a, y, x, 'E')  )
                mutare(a, y, x, 'E');

}


int main()
{
    int a[7][7], linie, coloana;
    char directie;
    initwindow (700, 700);
    initializare (a);
    desenareTabla();
    desenarePiese(a);

    // mutare(a, 3, 5, 'V');
    //  mutare (a, 5, 4, 'N');
    // mutare(a, 5, 4, 'S');
    // mutare(a, 4, 2, 'E');
    // mutare(a, 5, 2, 'E');
    //  mutare(a, 4, 0, 'E');
    //  mutareDubla(a, 4, 5, 'V');
do {
        utilizareMouse(a);
    } while (1);
    getch();
    closegraph();
    return 0;
}
