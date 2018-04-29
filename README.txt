Morgan Kelley
Class  Examples for MPI

Lecture 2: Exercise, Basic MPI Calls, Ping Pong
Description: Sends message from 1 to 0
mpicc P2P.cpp
ibrun -n 2 -o 0 a.out

Lecture 2: Exercise, Basic MPI Calls, Ping Pong
Description: Ping Pong
mpicc PingPong.cpp
ibrun -n 2 -o 0 a.out

Lecture 3/4: Experiment #2:
Description: Sends rank to all other nodes using send and recv
mpicc Experiment2.cpp
ibrun -n 9 -o 0 a.out

Lecture 3/4: Experiment #3
Description: Sends rank to all other nodes using Isend and Irecv
mpicc Experiment3.cpp
ibrun -n 9 -o 0 a.out

Lecture 4: In Class Lab #1:
Description: Uses reduction to find max of random values calculated by each node and reports the node which supplied the max.
mpicc Lab1.cpp
ibrun -n X -o 0 a.out

Lecture 9: Monte Carlo, PI
Description: Calculates pi by MCMC
mpicc PI_MCMC_Reduction.cpp
ibrun -n X -o 0 a.out

Lecture 9: Trapezoidal Rule, PI
Description: Calculates pi by the trapezoidal rule
mpicc Trap_Pi.cpp
ibrun -n X -o 0 a.out