all: main

assignment3: main.cpp
	gcc-c++ -O main.cpp -o main

test: main
	./test.sh

clean:
	rm -f main