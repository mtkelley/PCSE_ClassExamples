#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	MPI_Init(&argc,&argv);
	

int rank;
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
int size;
MPI_Comm_size(MPI_COMM_WORLD, &size);

if (size!=9){
fprintf(stderr,"The number of nodes must be nine\n");
MPI_Abort(MPI_COMM_WORLD,1);}

int i1[7]={2,3,4,5,6,7,8};
int i2[7]={1,3,4,5,6,7,8};
int i3[7]={2,1,4,5,6,7,8};
int i4[7]={2,3,1,5,6,7,8};
int i5[7]={2,3,4,1,6,7,8};
int i6[7]={2,3,4,5,1,7,8};
int i7[7]={2,3,4,5,6,1,8};
int i8[7]={2,3,4,5,6,7,1};

if (rank==1)
{for (int i=0;i<=6;i++)
		{MPI_Send(&rank, 1, MPI_INT, i1[i], rank, MPI_COMM_WORLD);
printf("%d sent its rank to: %d\n",rank,i1[i]);}}
		
else if (rank==2)
{for (int i=0;i<=6;i++)
		{MPI_Send(&rank, 1, MPI_INT, i2[i],rank, MPI_COMM_WORLD);
printf("%d sent its rank to: %d\n",rank,i2[i]);}}

else if (rank==3)
{for (int i=0;i<=6;i++)
		{MPI_Send(&rank, 1, MPI_INT, i3[i],rank, MPI_COMM_WORLD);
printf("%d sent its rank to: %d\n",rank,i3[i]);}}

else if (rank==4)
{for (int i=0;i<=6;i++)
	{MPI_Send(&rank, 1, MPI_INT, i4[i], rank, MPI_COMM_WORLD);
printf("%d sent its rank to: %d\n",rank,i4[i]);}}

else if (rank==5)
{for (int i=0;i<=6;i++)
		{MPI_Send(&rank, 1, MPI_INT, i5[i],rank, MPI_COMM_WORLD);
printf("%d sent its rank to: %d\n",rank,i5[i]);}}

else if (rank==6)
{for (int i=0;i<=6;i++)
		{MPI_Send(&rank, 1, MPI_INT, i6[i],rank, MPI_COMM_WORLD);
printf("%d sent its rank to: %d\n",rank,i6[i]);}}

else if (rank==7)
{for (int i=0;i<=6;i++)
	{MPI_Send(&rank, 1, MPI_INT, i7[i],rank, MPI_COMM_WORLD);
printf("%d sent its rank to: %d\n",rank,i7[i]);}}

else if (rank==8)
{for (int i=0;i<=6;i++)
		{MPI_Send(&rank, 1, MPI_INT, i8[i], rank, MPI_COMM_WORLD);
printf("%d sent its rank to: %d\n",rank,i8[i]);}}    

else 
printf("I am task %d\n",rank);
///////////////////////////////////////////////////////////////////
MPI_Barrier(MPI_COMM_WORLD);


int ti1[7]={2,3,4,5,6,7,8};
int ti2[7]={1,3,4,5,6,7,8};
int ti3[7]={2,1,4,5,6,7,8};
int ti4[7]={2,3,1,5,6,7,8};
int ti5[7]={2,3,4,1,6,7,8};
int ti6[7]={2,3,4,5,1,7,8};
int ti7[7]={2,3,4,5,6,1,8};
int ti8[7]={2,3,4,5,6,7,1};


if (rank==1)
{for (int i=0;i<=6;i++)
		{MPI_Recv(&rank, 1, MPI_INT,i1[i], i1[i], MPI_COMM_WORLD, MPI_STATUS_IGNORE);
printf("1 received rank from %d\n", ti1[i]);}}

else if (rank==2)
{for (int i=0;i<=6;i++)
		{MPI_Recv(&rank, 1, MPI_INT, i2[i], i2[i], MPI_COMM_WORLD, MPI_STATUS_IGNORE);
printf("2 received rank from %d\n", ti2[i]);}}

else if (rank==3)
{for (int i=0;i<=6;i++)
		{MPI_Recv(&rank, 1, MPI_INT, i3[i], i3[i], MPI_COMM_WORLD, MPI_STATUS_IGNORE);
printf("3 received rank from %d\n", ti3[i]);}}

else if (rank==4)
{for (int i=0;i<=6;i++)
	{MPI_Recv(&rank, 1, MPI_INT, i4[i], i4[i], MPI_COMM_WORLD, MPI_STATUS_IGNORE);
printf("4 received rank from %d\n", ti4[i]);}}

else if (rank==5)
{for (int i=0;i<=6;i++)
		{MPI_Recv(&rank, 1, MPI_INT, i5[i], i5[i], MPI_COMM_WORLD, MPI_STATUS_IGNORE);
printf("5 received rank from %d\n", ti5[i]);}}

else if (rank==6)
{for (int i=0;i<=6;i++)
		{MPI_Recv(&rank, 1, MPI_INT, i6[i], i6[i], MPI_COMM_WORLD, MPI_STATUS_IGNORE);
printf("6 received rank from %d\n", ti6[i]);}}

else if (rank==7)
{for (int i=0;i<=6;i++)
		{MPI_Recv(&rank, 1, MPI_INT, i7[i], i7[i], MPI_COMM_WORLD, MPI_STATUS_IGNORE);
printf("7 received rank from %d\n", ti7[i]);}}

else if (rank==8)
{for (int i=0;i<=6;i++)
		{MPI_Recv(&rank, 1, MPI_INT, i8[i], i8[i], MPI_COMM_WORLD, MPI_STATUS_IGNORE);
printf("8 received rank from %d\n", ti8[i]);}}
 
else
printf("I am task %d\n",rank);     
MPI_Finalize();
}
