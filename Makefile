out: clean compile execute

compile: main.cpp bootstrap.cpp
	g++ -g -Wall -std=c++14 main.cpp bootstrap.cpp -o mainexe

execute: mainexe
	./mainexe

clean:
	rm -f mainexe