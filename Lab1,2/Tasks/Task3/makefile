consonent : count_consonent_exe
	./count_consonent_exe
count_consonent_exe : count_consonent.o master.o
	gcc -o count_consonent_exe count_consonent.o master.o
count_consonent.o : count_consonent.c
	gcc -c count_consonent.c
master.o : master.c
	gcc -c master.c
clean :
	rm -f *.o
	rm count_consonent_exe