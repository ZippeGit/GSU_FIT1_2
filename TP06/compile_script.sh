gcc -c stack.c -o stack.o
gcc -c rpn.c -o rpn.o
gcc -c main.c -o main.o
gcc main.c stack.o rpn.o -o main -lm

