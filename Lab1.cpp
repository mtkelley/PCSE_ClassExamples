#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include <iostream>
#include <vector>
#include <functional>   // std::less_equal, std::bind2nd
#include <algorithm>    // std::count_if
#include<mpi.h>
#include<math.h>
#include <string.h>
using namespace std;

int main (int argc, char *argv[])
{  
int myid,nodenum, Maxnode, MN2;
float N, Nr;
MPI_Init(&argc,&argv); //Initialize MPI
MPI_Comm_rank(MPI_COMM_WORLD, &myid);
MPI_Comm_size(MPI_COMM_WORLD, &nodenum);

srand(time(NULL)+myid*myid); //Ensure all nodes get different number

N=rand()/(float)RAND_MAX;

printf("Node %d has number: %f\n",myid,N);

MPI_Reduce(&N,&Nr,1,MPI_FLOAT,MPI_MAX,0,MPI_COMM_WORLD);

if (N=Nr)
Maxnode=myid;
else
	Maxnode=0;

MPI_Reduce(&Maxnode,&MN2,MPI_INT,MPI_MAX,0,MPI_COMM_WORLD);

if (myid==0)
printf("Root node %d says the max is %f from node %d\n: ",myid,Nr,MN2);

MPI_Finalize();

}