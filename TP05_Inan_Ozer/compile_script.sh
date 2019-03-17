gcc -c patient.c -o patient.o
gcc -c main.c -o main.o
gcc main.c patient.o -o main -lm
