CFLAGS=-g

sorts: 
	gcc ${CFLAGS} -o bin/sorts sorts.c queue.c queue.h

clean:
	rm -f *.o bin/*

graph_client: graph.o queue.o
	gcc ${CFLAGS} -o bin/graph_client graph_client.c graph.o queue.o

graph.o:
	gcc ${CFLAGS} -c graph.c graph.h
queue.o:
	gcc ${CFLAGS} -c queue.c queue.h
stack.o:
	gcc ${CFALGS} -c stack.c stack.h
stack_client: stack.o
	gcc ${CFLAGS} -o bin/stack_client stack_client.c stack.o
