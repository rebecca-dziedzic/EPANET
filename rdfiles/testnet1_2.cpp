#include <stdio.h>
#include <conio.h>
#include "epanet2_2.h"
 

int runEpanet(char* inpFile, char* rptFile, char* outFile)
{
    int errcode;
    int   i, numNodes;
    long  t, tStep;
    double p;
    char  id[EN_MAXID + 1];
    EN_Project ph;
    errcode = EN_open(ph, "net1.inp", "net1.rpt", "");
    if (errcode == 0)
        {
            printf("%i",errcode);
        }
    EN_openH(ph);
    EN_initH(ph, EN_NOSAVE);
    do {
        EN_runH(ph, &t);
        for (i = 1; i <= numNodes; i++) {
            EN_getnodevalue(ph, i, EN_PRESSURE, &p);
            EN_getnodeid(ph, i, id);
            printf("%i, %d\n", id, p);
        }
        EN_nextH(ph, &tStep);
    } while (tStep > 0);
    EN_closeH(ph);

    EN_deleteproject(ph);
    return errcode;
}