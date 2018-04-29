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

MPI_Barrier(MPI_COMM_WORLD);

int i1[7]={2,3,4,5,6,7,8};
int i2[7]={1,3,4,5,6,7,8};
int i3[7]={2,1,4,5,6,7,8};
int i4[7]={2,3,1,5,6,7,8};
int i5[7]={2,3,4,1,6,7,8};
int i6[7]={2,3,4,5,1,7,8};
int i7[7]={2,3,4,5,6,1,8};
int i8[7]={2,3,4,5,6,7,1};


int rankr;
MPI_Status status;


if (rank==1)
{for (int i=0;i<=6;i++)
{MPI_Request req1;
	MPI_Isend(&rank, 1, MPI_INT, i1[i], rank, MPI_COMM_WORLD,&req1);
		printf("%d sent its rank to: %d\n",rank,i1[i]);
	MPI_Irecv(&rankr,1,MPI_INT,i1[i],i1[i],MPI_COMM_WORLD,&req1);
		printf("%d recieved rank from: %d\n",rank,i1[i]);

MPI_Wait(&req1,&status);}}
		
else if (rank==2)
{for (int i=0;i<=6;i++)
     	{MPI_Request req2;
	MPI_Isend(&rank, 1, MPI_INT, i2[i], rank, MPI_COMM_WORLD,&req2);
		printf("%d sent its rank to: %d\n",rank,i2[i]);
         MPI_Irecv(&rankr,1,MPI_INT,i2[i],i2[i],MPI_COMM_WORLD,&req2);
		printf("%d recieved rank from: %d\n",rank,i2[i]);
MPI_Wait(&req2,&status);}}

else if (rank==3)
{for (int i=0;i<=6;i++)
        {MPI_Request req3;
	MPI_Isend(&rank, 1, MPI_INT, i3[i], rank, MPI_COMM_WORLD,&req3);
		printf("%d sent its rank to: %d\n",rank,i3[i]);
	MPI_Irecv(&rankr,1,MPI_INT,i3[i],i3[i],MPI_COMM_WORLD,&req3);
		printf("%d recieved rank from: %d\n",rank,i3[i]);
MPI_Wait(&req3,&status);}}


else if (rank==4)
{for (int i=0;i<=6;i++)
        {MPI_Request req4;
        MPI_Isend(&rank, 1, MPI_INT, i4[i], rank, MPI_COMM_WORLD,&req4);
                printf("%d sent its rank to: %d\n",rank,i4[i]);
        MPI_Irecv(&rankr,1,MPI_INT,i4[i],i4[i],MPI_COMM_WORLD,&req4);
                printf("%d recieved rank from: %d\n",rank,i4[i]);
MPI_Wait(&req4,&status);}}


else if (rank==5)
{for (int i=0;i<=6;i++)
        {MPI_Request req5;
        MPI_Isend(&rank, 1, MPI_INT, i5[i], rank, MPI_COMM_WORLD,&req5);
                printf("%d sent its rank to: %d\n",rank,i5[i]);
        MPI_Irecv(&rankr,1,MPI_INT,i5[i],i5[i],MPI_COMM_WORLD,&req5);
                printf("%d recieved rank from: %d\n",rank,i5[i]);
MPI_Wait(&req5,&status);}}


else if (rank==6)
{for (int i=0;i<=6;i++)
        {MPI_Request req6;
        MPI_Isend(&rank, 1, MPI_INT, i6[i], rank, MPI_COMM_WORLD,&req6);
                printf("%d sent its rank to: %d\n",rank,i6[i]);
        MPI_Irecv(&rankr,1,MPI_INT,i6[i],i6[i],MPI_COMM_WORLD,&req6);
                printf("%d recieved rank from: %d\n",rank,i6[i]);
MPI_Wait(&req6,&status);}}


else if (rank==7)
{for (int i=0;i<=6;i++)
        {MPI_Request req7;
        MPI_Isend(&rank, 1, MPI_INT, i7[i], rank, MPI_COMM_WORLD,&req7);
                printf("%d sent its rank to: %d\n",rank,i7[i]);
        MPI_Irecv(&rankr,1,MPI_INT,i7[i],i7[i],MPI_COMM_WORLD,&req7);
                printf("%d recieved rank from: %d\n",rank,i7[i]);
MPI_Wait(&req7,&status);}}

else if (rank==8)
{for (int i=0;i<=6;i++)
        {MPI_Request req8;
        MPI_Isend(&rank, 1, MPI_INT, i8[i], rank, MPI_COMM_WORLD,&req8);
                printf("%d sent its rank to: %d\n",rank,i8[i]);
        MPI_Irecv(&rankr,1,MPI_INT,i8[i],i8[i],MPI_COMM_WORLD,&req8);
                printf("%d recieved rank from: %d\n",rank,i8[i]);
MPI_Wait(&req8,&status);}}

else 
printf("I am task %d\n",rank);
///////////////////////////////////////////////////////////////////
MPI_Barrier(MPI_COMM_WORLD);


MPI_Finalize();
}
