gcc -c DetectCycles.c
gcc -o exe DetectCycles.o 
valgrind ./exe
rm *.o
rm *exe