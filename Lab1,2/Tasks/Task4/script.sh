gcc -pg -c DynamicStringArray.c
gcc -pg -o exe DynamicStringArray.o
./exe
gprof exe gmon.out > profile_report.txt
rm -f *.o exe

