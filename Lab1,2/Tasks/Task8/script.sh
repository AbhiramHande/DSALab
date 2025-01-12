gcc -c CLL.c
gcc -o exe CLL.o 
valgrind ./exe
rm *.o
rm *exe