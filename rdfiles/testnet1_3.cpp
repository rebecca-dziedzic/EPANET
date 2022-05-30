#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "epanet2_2.h"

using namespace std;
 

int main (int argc, char* argv [])
{
    EN_Project ph;
    char *MyNode;
    int   i, N, nodeindex;
    long  t;
    double pressure;
 
    // Create a project
    EN_createproject(&ph);
 
    // Retrieve network data from an input file
    EN_open(ph, "Net1.inp", "", "");
 
    // Open the hydraulic solver
    EN_openH(ph);
 
    // Get the index of the node of interest
    EN_getnodeindex(ph, MyNode, &nodeindex);
 
    // Iterate over all demands
    for (i=1; i<N; i++)
    {
        
        EN_initH(ph, 0);
        EN_runH(ph, &t);
        EN_getnodevalue(ph, nodeindex, EN_PRESSURE, &pressure);
        printf("%d", pressure);
    }
 
    // Close hydraulics solver & delete the project
    EN_closeH(ph);
    EN_deleteproject(ph);
}