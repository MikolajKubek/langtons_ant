ant:
	cc -c ant.c antek.c matrix.c exporttopng.c 
	cc -o ant ant.o antek.o matrix.o exporttopng.o -lpng
clean:
	rm *.o
	rm ant
	
run:
	./ant
ant.o: ant.h ant.c antek.c matrix.h matrix.c exporttopng.h
antek.o: ant.h antek.c
matrix.o: matrix.h matrix.c
exporttopng.o: matrix.h matrix.c exporttopng.h exporttopng.c 
