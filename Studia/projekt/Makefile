ant:
	cc -c ant.c antek.c matrix.c  
	cc -o ant ant.o antek.o matrix.o 
clean:
	rm *.o
	rm ant
	
run:
	./ant
ant.o: ant.h ant.c antek.c matrix.h matrix.c 
antek.o: ant.h antek.c
matrix.o: matrix.h matrix.c
