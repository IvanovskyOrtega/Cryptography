a.out: main.o algoritmos.o
	g++ main.o algoritmos.o -Wall
main.o: main.cpp
	g++ -c main.cpp -Wall
algoritmos.o: algoritmos.cpp
	g++ -c algoritmos.cpp -Wall
clean:
	rm main.o algoritmos.o a.out
run: a.out
	./a.out
