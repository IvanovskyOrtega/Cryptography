a.out: main.o euclides.o
	g++ main.o euclides.o  -Wall
main.o: main.cpp
	g++ -c main.cpp -Wall
euclides.o: euclides.cpp
	g++ -c euclides.cpp -Wall
clean:
	rm main.o euclides.o a.out
run:
	./a.out