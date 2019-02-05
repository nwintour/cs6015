all: assignment3

assignment3: main.cpp
	clang++ -std=c++14 main.cpp -o main

make: all
	clang++ -std=c++14 main.cpp -o main

configure: all
	./configure

test: assignment3
	./test.sh

clean:
	rm -f main