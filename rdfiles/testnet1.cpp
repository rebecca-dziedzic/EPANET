#include <stdio.h>
#include <conio.h>
#include "epanet2_2.h"
 
void  writeConsole(char *s)
{
    fprintf(stdout, "\n%s", s);
}

void getPressures(EN_Project ph)
    {
    int   i, numNodes;
    long  t, tStep;
    double p;
    char  id[EN_MAXID + 1];
    EN_getcount(ph, EN_NODECOUNT, &numNodes);
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
    }

int runEpanet(char* inpFile, char* rptFile, char* outFile)
{
    int errcode;
    EN_Project ph;
    errcode = EN_open(ph, "net1.inp", "net1.rpt", "");
    if (errcode == 0)
        {
            // Call functions that perform desired analysis
        }
    getPressures(ph);

    EN_deleteproject(ph);
    return errcode;
}