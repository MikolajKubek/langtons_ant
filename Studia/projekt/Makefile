ant:
	cc -c ant.c main.c matrix.c exporttopng.c error.c 
	cc -o ant ant.o main.o matrix.o error.o  exporttopng.o -lpng
clean:
	rm *.o
	rm ant
run:
	./ant
ant.o: ant.h ant.c main.c matrix.h matrix.c exporttopng.h
main.o: ant.h main.c
matrix.o: matrix.h matrix.c
exporttopng.o: matrix.h matrix.c exporttopng.h exporttopng.c 
error.o: error.h error.c
