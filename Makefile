all: main

main: main.cpp
	clang++ -O main.cpp -lstdc++ -o main

test: main
	./test.sh

clean:
	rm -f main