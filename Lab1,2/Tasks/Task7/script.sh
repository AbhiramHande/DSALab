gcc -c LinkedList.c
gcc -o exe LinkedList.o 
valgrind ./exe
rm *.o
rm *exe