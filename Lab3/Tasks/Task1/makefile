runStackWithArray: stackDriver.o stack_array.o 
	gcc -o exe stackDriver.o stack_array.o
	./exe

stackDriver.o: stackDriver.c stack.h
	gcc -c stackDriver.c

stack_array.o: stack_array.c stack.h
	gcc -c stack_array.c
	
clean:
	rm -f *.o exe