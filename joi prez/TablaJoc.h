#include "Casuta.h"


#define DIM_TABLA 5

Casuta TablaJoc[DIM_TABLA][DIM_TABLA];

void desenareTablaContur(int culoareConturTabla = BLACK)
{

    int lin, col;
    for (lin = 0; lin < DIM_TABLA; lin++)
        for (col = 0; col < DIM_TABLA; col++)
        {
            setcolor(culoareConturTabla);
            int colt_stanga_sus_X = START_STANGA + LATURA_CASUTA * col;
            int colt_stanga_sus_Y = START_SUS    + LATURA_CASUTA * lin;
            int colt_dreapta_jos_X = START_STANGA + LATURA_CASUTA * (col + 1);
            int colt_dreapta_jos_Y = START_SUS    + LATURA_CASUTA * (lin + 1);
            rectangle(colt_stanga_sus_X,
                      colt_stanga_sus_Y,
                      colt_dreapta_jos_X,
                      colt_dreapta_jos_Y);
        }
    for(lin = 0; lin < DIM_TABLA; lin=lin+4)
        for (col = 0; col < DIM_TABLA; col=col+4)
        {
            desenareCasuta(lin, col, CASUTA_GAURA);
        }

    lin = 2;
    col = 2;
   desenareCasuta(lin, col, CASUTA_GAURA);
}

// citeste nivelul cu numarul "numarNivel"
// De ex : Nivelul X se gaseste la ../nivele/nivelX.txt
// nivelul este citit in matricea M (al 2lea param)

void citireNivel(int numarNivel, Casuta M[DIM_TABLA][DIM_TABLA])
{
    char denumireFisierNivel[256];
    char numarNivelString[256];

    // convertesc NumarNivel in string
    // il memorez in NumarNivelString
    // al treilea parametru este baza de numeratie
    itoa(numarNivel, numarNivelString, 10);

    strcpy(denumireFisierNivel, "nivele/nivel");
    strcat(denumireFisierNivel, numarNivelString);
    strcat(denumireFisierNivel, ".txt");

    std :: cout << denumireFisierNivel << '\n';

    std :: ifstream fin(denumireFisierNivel);
    int i,j;
    for(i = 0; i < DIM_TABLA; i++)
        for(j = 0; j < DIM_TABLA; j++)
        {
            M[i][j].lin = i;
            M[i][j].col = j;
            fin >> M[i][j].val;
        }
}
void desenareTabla(Casuta M[DIM_TABLA][DIM_TABLA])
{
    int i,j;
    for (i = 0; i < DIM_TABLA; i++)
        for (j = 0; j < DIM_TABLA; j++)
            desenareCasuta(i, j, M[i][j].val);
    desenareTablaContur();
}
