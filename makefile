assemble: main.o opCode.o
	g++ -std=c++11 main.o -o assemble

main.o: opCode.h main.cpp
	g++ -std=c++11 -c main.cpp

opCode.o: opCode.h opCode.cpp
	g++ -std=c++11 -c opCode.cpp

clean:
	rm -f *.o
	rm assemble

run: assemble
	./assemble


