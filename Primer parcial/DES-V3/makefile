a.out: main.o archivos.o des.o bits.o tiempo.o
	g++ main.o archivos.o des.o bits.o tiempo.o
main.o: main.cpp
	g++ -c main.cpp -Wall
archivos.o: archivos.cpp
	g++ -c archivos.cpp -Wall
des.o: des.cpp
	g++ -c des.cpp -Wall
bits.o: bits.cpp
	g++ -c bits.cpp -Wall
tiempo.o: tiempo.cpp
	g++ -c tiempo.cpp -Wall
clean:
	rm main.o archivos.o des.o a.out bits.o tiempo.o
run: a.out
	./a.out
