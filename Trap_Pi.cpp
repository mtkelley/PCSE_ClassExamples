#include <stdio.h>
#include<math.h>
#include <mpi.h>

main (int argc, char* argv[])
{
    int rank, size, error, i;
    double pi=0, result=0, Intsum=0, x2;
double  N=1E7;
double d=1E-7;
double d2=1E-14;
    
MPI_Init(&argc, &argv);
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    MPI_Comm_size (MPI_COMM_WORLD, &size);
    
    for (i=rank; i<N; i+=size)
    {
	x2=d2*i*i;
	result+=sqrt(1-x2);
	}

	MPI_Barrier(MPI_COMM_WORLD);
	
    MPI_Reduce(&result, &Intsum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank==0)
    {pi=4*d*Intsum;
	printf("PI=%lf\n",pi);}

    MPI_Finalize();
    
    return 0;
}
