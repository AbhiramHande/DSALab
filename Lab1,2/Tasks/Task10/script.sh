gcc -c CGPA.c 
gcc -c linked_list.c
gcc -o exe CGPA.o linked_list.o
./exe
rm -f *.o exe