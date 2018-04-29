#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include <math.h>
#include <time.h>
 
int main(int argc, char* argv[])
{
    int niter = 100000;
    int myid,i,rcount,rniter;                                       
    int count=0;             
    double z, pi,x,y;                                                    
 
    MPI_Init(&argc, &argv);                
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);      
 
    if(myid != 0)
    {for (i=0; i<niter; ++i)              
        {srand48(time(NULL));            
            x = (double)random()/RAND_MAX;      
            y = (double)random()/RAND_MAX;  
            z = sqrt((x*x)+(y*y));        
            if (z<=1)
			++count;}}
		
	
	MPI_Reduce(&count,&rcount,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    MPI_Reduce(&niter,&rniter, 1,MPI_INT, MPI_SUM,0,MPI_COMM_WORLD);
    rniter -= niter;  
 
    if (myid == 0)  
    {	pi = ((double)rcount/(double)rniter)*4.0;  
        printf("Pi: %f\n", pi);}
 
    MPI_Finalize();
    return 0;
}
