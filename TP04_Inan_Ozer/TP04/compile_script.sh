gcc -c linkedlist.c -o linkedlist.o
gcc -c main.c -o main.o
gcc main.c linkedlist.o -o main -lm

