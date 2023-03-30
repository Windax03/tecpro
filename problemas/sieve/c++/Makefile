all: sieve

sieve: sieve.cc
	g++ -std=c++11 -march=native -O3 -o $@ $<

go:
	sieve

clean:
	rm -f sieve *.o *.class
