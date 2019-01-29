all: main

main: main.cpp
	clang++ -O main.cpp -std=c++11 -o main

test: main
	./test.sh

clean:
	rm -f main