all: main

main: main.cpp
	clang++ main.cpp -o main

test: main
	./test.sh

clean:
	rm -f main