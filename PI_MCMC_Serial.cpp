#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void main(int argc, char* argv[])
{
double n = 10000000;
double x,y;
int i;
int count=0;
double z;
double pi;
srand(time(NULL));

//main loop
for (i=0; i<n; ++i)
{
//get random points
x = (double)random()/RAND_MAX;
y = (double)random()/RAND_MAX;
z = sqrt((x*x)+(y*y));
//check to see if point is in unit circle
if (z<=1)
{
++count;
}
}
pi = ((double)count/n)*4.0;
printf("Pi: %f\n", pi);
}
