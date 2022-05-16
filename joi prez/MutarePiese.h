#include "TablaJoc.h"

struct CoordTabla
{
    int Lin, Col;
};
bool gata;

bool miscare_posibila(Casuta M[DIM_TABLA][DIM_TABLA], CoordTabla a, CoordTabla b)
{
    if (M[a.Lin][a.Col].val != CASUTA_IEPURE)//daca unde am dat primul click nu e iepure
        return 0;
    if (M[b.Lin][b.Col].val != CASUTA_GOALA)//daca unde am dat al doilea click nu e spatiu gol pt a fi mutat iepurele
        return 0;

    // distantaSaritura pasi in cele 4 directii
    //   N, E, S,  V
    int dY[] = {-1, 0, 1,  0};
    int dX[] = { 0, 1, 0, -1};
    int distantaSaritura;
    int i, directie, distanta;
    bool estePeDirectie = 0;
    for (distantaSaritura = 2; distantaSaritura <= 6; distantaSaritura++)
    {
        for (i = 0; i < 4 && estePeDirectie == 0; i++)
        {
            // daca din a, mergand in directia i distantaSaritura pasi, obtin b
            if (a.Lin + dY[i] * distantaSaritura == b.Lin &&
                    a.Col + dX[i] * distantaSaritura == b.Col)
            {
                estePeDirectie = 1;
                //directie = i;
                //distanta = distantaSaritura;
                break;
            }
        }
        if (estePeDirectie != 0)
            break;
    }
    if (estePeDirectie == 0)
        return 0;
    // sunt la distanta (de 2 sau mai multe)
    // , deci trebuie sa verific intre ele
    // sa nu fie gol
    for (int j = 1; j < distantaSaritura; j++)
    {
        CoordTabla CasutaIntre;
        CasutaIntre.Lin = a.Lin + dY[i] * j;
        CasutaIntre.Col = a.Col + dX[i] * j;
        if (M[CasutaIntre.Lin][CasutaIntre.Col].val == CASUTA_GOALA)
            return 0;
    }
    // FAC MUTAREA
    return 1;
}
void mutare(Casuta M[DIM_TABLA][DIM_TABLA], CoordTabla a, CoordTabla b)
{
    if(miscare_posibila(M,a,b) == 1)
    {
        M[b.Lin][b.Col].val = CASUTA_IEPURE;
        M[a.Lin][a.Col].val = CASUTA_GOALA;
    }
    desenareTabla(M);
}

bool slide_vulpe_posibil(Casuta M[DIM_TABLA][DIM_TABLA],CoordTabla a, CoordTabla b, int directie)
{
    int i,x,j,y;
    if(directie == 0)//v
    {
        if (M[a.Lin][a.Col].val == CASUTA_VULPE_CAP_ORIZ )
        {
            x=a.Col-1;
            y=b.Col;
        }
        else if(M[a.Lin][a.Col].val == CASUTA_VULPE_COADA_ORIZ)
        {
            x=a.Col-2;
            y=b.Col-1;
        }

        for(j = x; j >= y; j--)
        {
            if( M[a.Lin][j].val != CASUTA_GOALA )
                return 0;
        }
        return 1;
    }
    else if(directie == 1)//e
    {
        if (M[a.Lin][a.Col].val == CASUTA_VULPE_CAP_ORIZ )
        {
            x=a.Col+2;
            y=b.Col+1;
        }
        else if(M[a.Lin][a.Col].val == CASUTA_VULPE_COADA_ORIZ)
        {
            x=a.Col+1;
            y=b.Col;
        }

        for(j = x; j <= y; j++)
        {
            if( M[a.Lin][j].val != CASUTA_GOALA )
                return 0;
        }
        return 1;
    }
    else if(directie == 2)//n
    {
        if (M[a.Lin][a.Col].val == CASUTA_VULPE_CAP_VERT)
        {
            x=a.Lin-1;
            y=b.Lin;
        }
        else if(M[a.Lin][a.Col].val == CASUTA_VULPE_COADA_VERT)
        {
            x=a.Lin-2;
            y=b.Lin+1;
        }

        for(i = x; i >= y; i--)
        {
            if( M[i][a.Col].val != CASUTA_GOALA )
                return 0;
        }
        return 1;
    }
    else if(directie == 3)//s
    {
        if (M[a.Lin][a.Col].val == CASUTA_VULPE_CAP_VERT )
        {
            x=a.Lin+2;
            y=b.Lin+1;
        }
        else if(M[a.Lin][a.Col].val == CASUTA_VULPE_COADA_VERT)
        {
            x=a.Lin+1;
            y=b.Lin;
        }

        for(i = x; i <= y; i++)
        {
            if( M[i][a.Col].val != CASUTA_GOALA )
                return 0;
        }
        return 1;
    }
    return 0;
}

void slide_vulpe(Casuta M[DIM_TABLA][DIM_TABLA],CoordTabla a, CoordTabla b,int directie)
{

    if(slide_vulpe_posibil(M, a, b, directie) == 1)
    {
        if(directie == 0)//v
        {
            if( M[a.Lin][a.Col].val == CASUTA_VULPE_CAP_ORIZ && b.Col>=0)
            {
                M[a.Lin][a.Col].val = CASUTA_GOALA;
                M[a.Lin][a.Col+1].val = CASUTA_GOALA;

                M[b.Lin][b.Col].val = CASUTA_VULPE_CAP_ORIZ;
                M[b.Lin][b.Col+1].val = CASUTA_VULPE_COADA_ORIZ;
            }
            else if(M[a.Lin][a.Col].val == CASUTA_VULPE_COADA_ORIZ && b.Col-1>=0)
            {

                M[a.Lin][a.Col].val = CASUTA_GOALA;
                M[a.Lin][a.Col-1].val = CASUTA_GOALA;

                M[b.Lin][b.Col].val = CASUTA_VULPE_COADA_ORIZ;
                M[b.Lin][b.Col-1].val = CASUTA_VULPE_CAP_ORIZ;
            }
        }
        else if(directie == 1)//e
        {

            if(M[a.Lin][a.Col].val == CASUTA_VULPE_CAP_ORIZ && b.Col<=3 )
            {
                M[a.Lin][a.Col].val = CASUTA_GOALA;
                M[a.Lin][a.Col+1].val = CASUTA_GOALA;

                M[b.Lin][b.Col].val = CASUTA_VULPE_CAP_ORIZ;
                M[b.Lin][b.Col+1].val = CASUTA_VULPE_COADA_ORIZ;
            }
            else if(M[a.Lin][a.Col].val == CASUTA_VULPE_COADA_ORIZ && b.Col<=4)
            {

                M[a.Lin][a.Col].val = CASUTA_GOALA;
                M[a.Lin][a.Col-1].val = CASUTA_GOALA;

                M[b.Lin][b.Col].val = CASUTA_VULPE_COADA_ORIZ;
                M[b.Lin][b.Col-1].val = CASUTA_VULPE_CAP_ORIZ;
            }
        }
        else if( directie == 2)//n
        {
            if(M[a.Lin][a.Col].val == CASUTA_VULPE_CAP_VERT && b.Lin>=0)
            {
                M[a.Lin][a.Col].val = CASUTA_GOALA;
                M[a.Lin+1][a.Col].val = CASUTA_GOALA;

                M[b.Lin][b.Col].val = CASUTA_VULPE_CAP_VERT;
                M[b.Lin+1][b.Col].val = CASUTA_VULPE_COADA_VERT;

            }
            else if(M[a.Lin][a.Col].val == CASUTA_VULPE_COADA_VERT && b.Lin>=1)
            {

                M[a.Lin][a.Col].val = CASUTA_GOALA;
                M[a.Lin-1][a.Col].val = CASUTA_GOALA;

                M[b.Lin][b.Col].val = CASUTA_VULPE_CAP_VERT;
                M[b.Lin+1][b.Col].val = CASUTA_VULPE_COADA_VERT;

            }

        }
        else if( directie == 3)//s
        {
            if(M[a.Lin][a.Col].val == CASUTA_VULPE_CAP_VERT && b.Lin<=3)
            {
                M[a.Lin][a.Col].val = CASUTA_GOALA;
                M[a.Lin+1][a.Col].val = CASUTA_GOALA;

                M[b.Lin][b.Col].val = CASUTA_VULPE_CAP_VERT;
                M[b.Lin+1][b.Col].val = CASUTA_VULPE_COADA_VERT;

            }
            else if(M[a.Lin][a.Col].val == CASUTA_VULPE_COADA_VERT && b.Lin<=4)
            {

                M[a.Lin][a.Col].val = CASUTA_GOALA;
                M[a.Lin-1][a.Col].val = CASUTA_GOALA;

                M[b.Lin][b.Col].val = CASUTA_VULPE_COADA_VERT;
                M[b.Lin-1][b.Col].val = CASUTA_VULPE_CAP_VERT;

            }
        }

    }
    desenareTabla(M);
}
void getLinCol(int x, int y, int &lin, int &col)
{
    lin = (y - START_SUS) / LATURA_CASUTA;
    col = (x - START_STANGA) / LATURA_CASUTA;
}
void selectare_casute(Casuta M[DIM_TABLA][DIM_TABLA],int lin, int col)
{
    //daca casuta pe care am dat click e un iepure
    //selectez casuta printr-o subliniere (highlight)

    if( M[lin][col].val == CASUTA_IEPURE)
        desenareCasuta(lin, col, CASUTA_HIGHLIGHT);

    //daca este o vulpe orizontala
    //1.cap de vulpe - V

    else if(M[lin][col].val == CASUTA_VULPE_CAP_ORIZ)
    {
        desenareCasuta(lin, col, CASUTA_HIGHLIGHT);
        desenareCasuta(lin, col+1, CASUTA_HIGHLIGHT);
    }
    //2.coada de vulpe - E

    else if ( M[lin][col].val == CASUTA_VULPE_COADA_ORIZ)
    {
        desenareCasuta(lin, col, CASUTA_HIGHLIGHT);
        desenareCasuta(lin, col-1, CASUTA_HIGHLIGHT);
    }
    //daca este o vulpe vericala
    //1.cap de vulpe - N
    else if(M[lin][col].val == CASUTA_VULPE_CAP_VERT)
    {
        desenareCasuta(lin, col, CASUTA_HIGHLIGHT);
        desenareCasuta(lin+1, col, CASUTA_HIGHLIGHT);
    }
    //2.coada de vulpe - S
    else if ( M[lin][col].val == CASUTA_VULPE_COADA_VERT)
    {
        desenareCasuta(lin, col, CASUTA_HIGHLIGHT);
        desenareCasuta(lin-1, col, CASUTA_HIGHLIGHT);
    }
    else if ( M[lin][col].val == CASUTA_GOALA)
    {
        desenareCasuta(lin, col, CASUTA_HIGHLIGHT_REMOVE);
    }
}
bool delimitareTabla(Casuta M[DIM_TABLA][DIM_TABLA],CoordTabla x)
{
    if(x.Lin < 0 || x.Lin > 5 || x.Col < 0 || x.Col > 5)
        return 0;
    return 1;

}
void Punere_Piese(Casuta M[DIM_TABLA][DIM_TABLA])
{
    bool click;
    int lin,col;
    int x,y;
    int lin1,col1;
    int x1,y1;
    CoordTabla casuta1, casuta2;
    int directie;

    click=false;
    while(!click)
    {
        if(ismouseclick(WM_LBUTTONDOWN))//primul click
        {
            click = true;
            getmouseclick(WM_LBUTTONDOWN, x, y);
            getLinCol(x, y, lin, col);//identific linia si coloana pt primul click

            casuta1.Lin = lin;
            casuta1.Col = col;
            if(delimitareTabla( M,casuta1) == 1)
                selectare_casute(M,lin,col);

            click=false;
            while(!click)
            {
                //click = false;
                if(ismouseclick(WM_LBUTTONDOWN))//al doilea click
                {
                    click = true;
                    getmouseclick(WM_LBUTTONDOWN, x1, y1);

                    getLinCol(x1, y1, lin1, col1);

                    casuta2.Lin = lin1;
                    casuta2.Col = col1;
                    if(delimitareTabla( M, casuta2)== 1)
                    {

                        if (miscare_posibila(M, casuta1, casuta2) == 1)//daca este posibila miscarea iepurelui
                        {
                            PlaySound(TEXT("click.wav"), NULL, SND_ASYNC);
                            mutare(M, casuta1, casuta2) ;
                            selectare_casute(M, lin1, col1);
                        }
                        //daca este posibila miscarea vulpii
                        //1.orizontala
                        else if( lin == lin1 && col1-col < 0 && slide_vulpe_posibil(M, casuta1, casuta2, 0) == 1)//v
                        {
                            PlaySound(TEXT("click.wav"), NULL, SND_ASYNC);
                            slide_vulpe(M, casuta1, casuta2, 0);
                            selectare_casute(M, lin1, col1);
                        }
                        else if( lin == lin1 && col1-col > 0 && slide_vulpe_posibil(M, casuta1, casuta2, 1) == 1)//e
                        {
                            PlaySound(TEXT("click.wav"), NULL, SND_ASYNC);
                            slide_vulpe(M, casuta1, casuta2, 1);
                            selectare_casute(M, lin1, col1);
                        }
                        //2.verticala
                        else if( col == col1 && lin1-lin < 0 && slide_vulpe_posibil(M, casuta1, casuta2, 2) == 1)//n
                        {
                            PlaySound(TEXT("click.wav"), NULL, SND_ASYNC);
                            slide_vulpe(M, casuta1, casuta2, 2);
                            selectare_casute(M, lin1, col1);
                        }
                        else if( col == col1 && lin1-lin > 0 && slide_vulpe_posibil(M, casuta1, casuta2, 3) == 1)//s
                        {
                            PlaySound(TEXT("click.wav"), NULL, SND_ASYNC);
                            slide_vulpe(M, casuta1, casuta2, 3);
                            selectare_casute(M, lin1, col1);
                        }
                        else
                        {
                            desenareCasuta(lin, col, CASUTA_HIGHLIGHT_REMOVE);
                            desenareCasuta(lin1, col1, CASUTA_HIGHLIGHT_REMOVE);
                        }

                        desenareCasuta(lin1, col1, CASUTA_HIGHLIGHT_REMOVE);
                    }
                }
            }
        }
    }
}
int NumarareIepuri(Casuta M[DIM_TABLA][DIM_TABLA])
{
    int nrIepuri=0;
    for(int i=0; i<DIM_TABLA; i++)
        for(int j=0; j<DIM_TABLA; j++)
        {
            if(M[i][j].val == CASUTA_IEPURE)
                nrIepuri++;
        }
    return nrIepuri;
}
bool IepuriInGauri(Casuta M[DIM_TABLA][DIM_TABLA])
{
    int nrIepuri = NumarareIepuri(M);
    int nr=0;
    if(M[0][0].val == CASUTA_IEPURE )
        nr++;
    if(M[0][4].val == CASUTA_IEPURE )
        nr++;
    if(M[2][2].val == CASUTA_IEPURE )
        nr++;
    if(M[4][0].val == CASUTA_IEPURE )
        nr++;
    if(M[4][4].val == CASUTA_IEPURE )
        nr++;

    if(nrIepuri == nr)
        return 1;
    else return 0;
}
