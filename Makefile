all: main

main: main.cpp
	gcc -O man.cpp -lstdc++ -o main

test: main
	./test.sh

clean:
rm -f main
