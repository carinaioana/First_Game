#include "LibPredefinite.h"

#include "ConstanteEcran.h"

struct Casuta
{
    int val; // tipul de casuta
    int lin, col;
};

/* Deseneaza o casuta:
    la linia   : lin
    la coloana : col
    de tipul   : tipCasuta
*/
void desenareCasuta(int lin, int col, int tipCasuta)
{
    const int colt_stanga_sus_X = START_STANGA + LATURA_CASUTA * col;
    const int colt_stanga_sus_Y = START_SUS    + LATURA_CASUTA * lin;
    const int colt_dreapta_jos_X = START_STANGA + LATURA_CASUTA * (col + 1);
    const int colt_dreapta_jos_Y = START_SUS    + LATURA_CASUTA * (lin + 1);
    switch (tipCasuta)
    {
    case CASUTA_HIGHLIGHT_REMOVE:
        setcolor ( CULOARE_HIGHLIGHT_REMOVE );
        rectangle(colt_stanga_sus_X,
                  colt_stanga_sus_Y,
                  colt_dreapta_jos_X,
                  colt_dreapta_jos_Y);
    case CASUTA_HIGHLIGHT:
        setcolor ( CULOARE_HIGHLIGHT );
        rectangle(colt_stanga_sus_X,
                  colt_stanga_sus_Y,
                  colt_dreapta_jos_X,
                  colt_dreapta_jos_Y);
        break;

    case CASUTA_GOALA:
        setfillstyle(SOLID_FILL, CULOARE_FUNDAL);
        bar(colt_stanga_sus_X,
            colt_stanga_sus_Y,
            colt_dreapta_jos_X,
            colt_dreapta_jos_Y);
        break;
    case CASUTA_IEPURE:
        readimagefile("iepure.jpg",
                      colt_stanga_sus_X,
                      colt_stanga_sus_Y,
                      colt_dreapta_jos_X,
                      colt_dreapta_jos_Y);
        break;
    case CASUTA_CIUPERCA:
        readimagefile("ciuperca.jpg",
                      colt_stanga_sus_X,
                      colt_stanga_sus_Y,
                      colt_dreapta_jos_X,
                      colt_dreapta_jos_Y);
        break;
    case CASUTA_VULPE_CAP_ORIZ:
        readimagefile("vulpe_cap.jpg",
                      colt_stanga_sus_X,
                      colt_stanga_sus_Y,
                      colt_dreapta_jos_X,
                      colt_dreapta_jos_Y);
        break;
    case CASUTA_VULPE_COADA_ORIZ:
        readimagefile("vulpe_coada.jpg",
                      colt_stanga_sus_X,
                      colt_stanga_sus_Y,
                      colt_dreapta_jos_X,
                      colt_dreapta_jos_Y);
        break;
    case CASUTA_VULPE_CAP_VERT:
        readimagefile("vulpe_cap_1.jpg",
                      colt_stanga_sus_X,
                      colt_stanga_sus_Y,
                      colt_dreapta_jos_X,
                      colt_dreapta_jos_Y);
        break;
    case CASUTA_VULPE_COADA_VERT:

        readimagefile("vulpe_coada_1.jpg",
                      colt_stanga_sus_X,
                      colt_stanga_sus_Y,
                      colt_dreapta_jos_X,
                      colt_dreapta_jos_Y);
        break;
        case CASUTA_GAURA:
            setcolor(BLACK);
            circle(START_STANGA + LATURA_CASUTA * col+ LATURA_CASUTA / 2,
                   START_SUS + LATURA_CASUTA * lin + LATURA_CASUTA / 2,
                   49);
        break;


    }
}
