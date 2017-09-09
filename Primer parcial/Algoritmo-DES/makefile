a.out: main.o archivos.o des.o
	g++ main.o archivos.o des.o
main.o: main.cpp
	g++ -c main.cpp -Wall
archivos.o: archivos.cpp
	g++ -c archivos.cpp -Wall
des.o: des.cpp
	g++ -c des.cpp -Wall
clean:
	rm main.o archivos.o des.o a.out
run: a.out
	./a.out