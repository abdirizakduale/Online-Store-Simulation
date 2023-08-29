all: exe

exe: main.o node.o electronics.o
	g++ -Wall -g -o exe main.o node.o electronics.o

main.o: main.cpp
	g++ -Wall -g -c main.cpp

node.o: node.cpp
	g++ -Wall -g -c node.cpp

electronics.o: electronics.cpp
	g++ -Wall -g -c electronics.cpp

clean:
	rm -f *.o exe