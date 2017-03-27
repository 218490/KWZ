cpm: main.cpp projekt.cpp zadanie.cpp projekt.hh zadanie.hh
	g++ -Wall -std=c++11 -o cpm main.cpp projekt.cpp zadanie.cpp

clean:
	rm -f cpm *~
