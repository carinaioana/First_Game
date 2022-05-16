#include "MutarePiese.h"

int NumarareIepuri(Casuta M[DIM_TABLA][DIM_TABLA],int nivelJoc=1)
{
    int nrIepuri=0;
    citireNivel(nivelJoc, M);
    for(i=0;i<=DIM_TABLA;i++)
        for(j=0;j<=DIM_TABLA;j++)
    {
        if(M[i][j].val == CASUTA_IEPURE)
            nrIepuri++;
    }
    return nrIepuri;
}
bool IepuriInGauri(Casuta M[DIM_TABLA][DIM_TABLA])
{
    int nrIepuri=NumarareIepuri(M,nivelJoc);
    int nr;
    for(i=0;i<=DIM_TABLA;i++)
        for(j=0;j<=DIM_TABLA;j++)
        {

            if(M[i][j].val == CASUTA_IEPURE && M[i][j].val == CASUTA_GAURA)
                nr++;
        }
    if(nrIepuri == nr)
        return 1;
    else return 0;
}
