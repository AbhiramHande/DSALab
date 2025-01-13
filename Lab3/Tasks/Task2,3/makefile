runStackWithLinkedList: stackDriver.o stack_linked_list.o linked_list.o
	gcc -o exe stackDriver.o stack_linked_list.o linked_list.o
	./exe

stackDriver.o: stackDriver.c stack.h
	gcc -c stackDriver.c

stack_linked_list.o: stack_linked_list.c stack.h linked_list.h
	gcc -c stack_linked_list.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

clean:
	rm -f *.o exe