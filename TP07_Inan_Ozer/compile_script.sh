gcc -c hash.c -o hash.o
gcc -c main.c -o main.o
gcc main.c hash.o -o main 
