gcc -c count_consonent.c
gcc -c master.c
gcc -o count_consonent_exe count_consonent.o master.o
./count_consonent_exe
rm *.o
rm *exe