#include "MutarePiese.h"

using namespace std;
void pagina_start();
void pagina_meniu();
void pagina_niveluri();
void pagina_joc(int nivelJoc);
void pagina_reguli();

void pagina_start()
{
    initwindow(ECRAN_LATIME, ECRAN_INALTIME);
    int font=6;
    int direction=0;
    int font_size=6;

    readimagefile("padure.jpg", 0, 0, ECRAN_LATIME, ECRAN_INALTIME);
    setcolor(LIGHTGREEN);
    settextstyle(font, direction, font_size);
    outtextxy( 260, 230, "JUMP IN");

    bool isClicked=0;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            isClicked=1;
            clearmouseclick(WM_LBUTTONDOWN);
            if(mousex()>=0 && mousex()<=ECRAN_LATIME && mousey()>=0 && mousey()<=ECRAN_INALTIME)
            {
                PlaySound(TEXT("click.wav"), NULL, SND_ASYNC);
                pagina_meniu();
            }
        }
    }while(isClicked==0);

    getch();
    closegraph();
}
void pagina_meniu()
{
    initwindow(ECRAN_LATIME, ECRAN_INALTIME);
    readimagefile("pagina_meniu.jpg", 0, 0, ECRAN_LATIME, ECRAN_INALTIME);

    //stilul textului
    int font=8;
    //directia textului (vertical, orizontal)
    int direction=0;
    //marimea textului
    int font_size=5;
    setcolor(RGB(0, 77, 0));
    setbkcolor(RGB(204, 255, 153));

    //locatia textului

    int x1=347;
    int y1=200;
    settextstyle(font, direction, font_size);
    outtextxy(x1, y1, "Play");
    //bar(x1-1,y1,x1+105,y1+42);

    int x2=337;
    int y2=y1+100;
    settextstyle(font, direction, font_size);
    outtextxy(x2, y2, "Rules");
    //bar(x-2, y2, x2+125, y2+42);

    bool isClicked=0;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            isClicked=1;
            clearmouseclick(WM_LBUTTONDOWN);
            if(mousex()>=x1 && mousex()<=x1+105 && mousey()>=y1 && mousey()<=y1+42)
            {
                PlaySound(TEXT("click.wav"), NULL, SND_ASYNC);
                pagina_niveluri();
            }
            else
            if(mousex()>=x2 && mousex()<=x2+209 && mousey()>=y2 && mousey()<=y2+42)
            {
                PlaySound(TEXT("click.wav"), NULL, SND_ASYNC);
                pagina_reguli();
            }
            else
                isClicked=0;
        }
    }while(isClicked==0);

    getch();
    closegraph();
}

void pagina_niveluri()
{
    initwindow(ECRAN_LATIME, ECRAN_INALTIME);
    int lin, col;
    readimagefile("pagina_niveluri.jpg", 0, 0, ECRAN_LATIME, ECRAN_INALTIME);
    int NRLIN = 5;
    int NRCOL = 6;
    for (lin = 0; lin < NRLIN; lin++)
        for (col = 0; col < NRCOL; col++)
        {
            setcolor(BLACK);
            int x = START_STANGA;
            int y = START_SUS;
            int colt_stanga_sus_X =x + LATURA_CASUTA * col;
            int colt_stanga_sus_Y = y   + LATURA_CASUTA * lin;
            int colt_dreapta_jos_X = x + LATURA_CASUTA * (col + 1);
            int colt_dreapta_jos_Y = y    + LATURA_CASUTA * (lin + 1);
            rectangle(colt_stanga_sus_X,
                      colt_stanga_sus_Y,
                      colt_dreapta_jos_X,
                      colt_dreapta_jos_Y);
        }

    int font=6;
    int direction=0;
    int font_size=3;
    setcolor(RGB(153, 102, 0));
    setbkcolor(RGB(204, 255, 255));

    settextstyle(font, direction, font_size);
    int x=180;
    int y=90;

    int i, j;
    for (i = 0; i < NRLIN; i++)
        for (j = 0; j < NRCOL; j++)
        {
            int nivel = j+1 + i * NRCOL;
            char nivelString[4];
            itoa(nivel, nivelString, 10);
            outtextxy(x + j * 100, y + i * 100, nivelString);
        }
    font=8;
    direction=0;
    font_size=5;
    int x1=20;
    int y1=20;
    settextstyle(font, direction, font_size);
    outtextxy(x1, y1, "Back");
    //bar(x1-1,y1,x1+125,y1+40);

    bool isClicked = 0;
    do
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            isClicked = 1;
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if(mousex()>=x1 && mousex()<=x1+125 && mousey()>=y1 && mousey()<=y1+40)
            {
                PlaySound(TEXT("click.wav"), NULL, SND_ASYNC);
                pagina_meniu();
            }
            else
                isClicked=0;
            int lin = (y - START_SUS) / LATURA_CASUTA;
            int col = (x - START_STANGA) / LATURA_CASUTA;
            if (lin >= 0 && lin < NRLIN && col >= 0 && col < NRCOL)
            {
                int nivel = col + 1 + lin * NRCOL;
                pagina_joc(nivel);
            }
            else
                isClicked=0;
        }
    }while(0 == isClicked);

    getch();
    closegraph();
}


void pagina_reguli()
{
    initwindow(ECRAN_LATIME, ECRAN_INALTIME);
    readimagefile("pagina_reguli.jpg", 0, 0, ECRAN_LATIME, ECRAN_INALTIME);
    int x=20;
    int y1=90;
    //stilul textului
    int font=8;
    //directia textului (vertical, orizontal)
    int direction=0;
    //marimea textului
    int font_size=1;
    setcolor(WHITE);
    setbkcolor(RGB(145, 102, 59));

    settextstyle(font, direction, font_size);
    outtextxy(x, y1, "Etapele jocului:");
    int y2=y1+50;
    outtextxy(x, y2, "1. Alegi o provocare.");
    outtextxy(x, y2+20, "   Toate piesele de joc vor fi asezate conform provocarii.");
    int y3=y2+50;
    outtextxy(x, y3, "2. Obiectivul jocului este sa muti iepurasii si vulpile pe tabla de ");
    outtextxy(x, y3+20, "   joc astfel incat toti iepurasii sa fie in siguranta in gaura lor.");
    int y4=y3+50;
    outtextxy(x, y4, "3. Jocul e terminat in momentul in care toti iepurasii sunt in gaura ");
    outtextxy(x, y4+20, "   lor. In functie de numarul de miscari in care a fost terminata ");
    outtextxy(x, y4+40, "   provocarea, jucatorul va primi fie 1,2, sau 3 stele.");
    int y5=y4+80;
    outtextxy(x, y5, "Reguli:");
    int y6=y5+50;
    outtextxy(x, y6, "Iepurasii trebuie sa sara mereu doar peste ciuperci, peste alti ");
    outtextxy(x, y6+20, "  iepuri, peste vulpi, sau oricare alta combinatie de obstacole.");
    int y7=y6+50;
    outtextxy(x, y7, "Iepurasii pot sari si peste 2 sau mai multe obstacole. ");
    int y8=y7+50;
    outtextxy(x, y8, "Vulpile pot doar sa alunece.(“slide”) ");
    int y9=y8+50;
    outtextxy(x, y9, "Jocul are o singura varianta de rezolvare. ");

    int x1=20;
    int y10=20;
    font_size=5;
    settextstyle(font, direction, font_size);
    outtextxy(x1, y10, "Back");
    //bar(x1-1,y10,x1+125,y10+40);

    bool isClicked=0;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            isClicked=1;
            clearmouseclick(WM_LBUTTONDOWN);
            if(mousex()>=x1 && mousex()<=x1+125 && mousey()>=y10 && mousey()<=y10+40)
            {
                PlaySound(TEXT("click.wav"), NULL, SND_ASYNC);
                pagina_meniu();
            }
            else
                isClicked=0;
        }
    }while(isClicked==0);

    getch();
    closegraph();
}



void pagina_levelup()
{
    initwindow(ECRAN_LATIME, ECRAN_INALTIME);
    readimagefile("levelup.jpg", 0, 0,ECRAN_LATIME, ECRAN_INALTIME);

    //stilul textului
    int font=6;
    //directia textului (vertical, orizontal)
    int direction=0;
    //marimea textului
    int font_size=5;

    setcolor(WHITE);
    setbkcolor(RGB(0, 204, 255));

    int x=640;
    int y=20;
    settextstyle(font, direction, font_size);
    outtextxy(x, y, "Next");
    //bar(x-1, y, x+125, y+42);

    PlaySound(TEXT("levelup.wav"), NULL, SND_SYNC);

    bool isClicked=0;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            isClicked=1;
            clearmouseclick(WM_LBUTTONDOWN);
            if(mousex()>=x && mousex()<=x+125 && mousey()>=y && mousey()<=y+42)
            {
                PlaySound(TEXT("click.wav"), NULL, SND_ASYNC);
                pagina_niveluri();
            }
            else
                isClicked=0;
        }
    }while(isClicked==0);

    getch();
    closegraph();
}

void pagina_tryagain()
{
    initwindow(ECRAN_LATIME, ECRAN_INALTIME);
    readimagefile("tryagain.jpg", 0, 0, ECRAN_LATIME, ECRAN_INALTIME);

    //stilul textului
    int font=6;
    //directia textului (vertical, orizontal)
    int direction=0;
    //marimea textului
    int font_size=5;

    setcolor(RGB(255, 255, 0));
    setbkcolor(RGB(169, 0, 0));

    int x=20;
    int y=20;
    settextstyle(font, direction, font_size);
    outtextxy(x, y, "Back");
    //bar(x-1, y, x+126, y+42);

    PlaySound(TEXT("tryagain.wav"), NULL, SND_ASYNC);

    bool isClicked=0;
    do
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            isClicked=1;
            clearmouseclick(WM_LBUTTONDOWN);
            if(mousex()>=x && mousex()<=x+126 && mousey()>=y && mousey()<=y+42)
            {
                PlaySound(TEXT("click.wav"), NULL, SND_ASYNC);
                pagina_niveluri();
            }
            else
                isClicked=0;
        }
    }while(isClicked==0);

    getch();
    closegraph();
}

void pagina_finish(Casuta M[DIM_TABLA][DIM_TABLA],int nivelJoc=1)
{
    initwindow(ECRAN_LATIME, ECRAN_INALTIME);
    setbkcolor(CULOARE_FUNDAL);
    if(IepuriInGauri(M) == 1)
        pagina_levelup();

    else
        pagina_tryagain();
}

void pagina_joc(int nivelJoc = 1)
{

    initwindow(ECRAN_LATIME, ECRAN_INALTIME);
    setbkcolor(RGB(0, 51, 0));
    clearviewport();
    readimagefile("fundal1.jpg", 0, 0, ECRAN_LATIME, ECRAN_INALTIME);
    Casuta M[DIM_TABLA][DIM_TABLA];
    // Citesc nivelul 1 in matricea M
    PlaySound(TEXT("click.wav"), NULL, SND_ASYNC);
    citireNivel(nivelJoc, M);
    // desenez tabla dupa valorile din matricea M
    desenareTabla(M);

    int x=20;
    int y=20;
    //stilul textului
    int font=8;
    //directia textului (vertical, orizontal)
    int direction=0;
    //marimea textului
    int font_size=5;
    setcolor(RGB(102, 255, 102));
    settextstyle(font, direction, font_size);
    outtextxy(x, y, "Back");
    //bar(x-1, y, x+125, y+42);

    int x1=630;
    int y1=551;
    settextstyle(font, direction, font_size);
    outtextxy(x1, y1, "Finish");
    //bar(x1-1, y1, x1+158, y1+42);

    while(1)
    {
        Punere_Piese(M);

        if(mousex()>=x && mousex()<=x+125 && mousey()>=y && mousey()<=y+42)
        {
            PlaySound(TEXT("click.wav"), NULL, SND_ASYNC);
            pagina_niveluri();
        }
        else
        if(mousex()>=x1 && mousex()<=x1+158 && mousey()>=y1 && mousey()<=y1+42)
        {
            PlaySound(TEXT("click.wav"), NULL, SND_SYNC);
            pagina_finish(M);
        }
    }

    getch();
    closegraph();

}

int main()
{
    pagina_start();

    getch();
    return 0;
}
