all: assignment3

assignment3: main.cpp
	clang++ -std=c++14 main.cpp -o main

make: all
	clang++ -std=c++14 main.cpp -o main

configure: all
	./configure

test: all
	./test.sh

coverage:
	clang++ -fprofile-instr-generate -fcoverage-mapping main.cpp -o main
	LLVM_PROFILE_FILE="main.profraw" ./main
	xcrun llvm-profdata merge -sparse main.profraw -o main.profdata
	xcrun llvm-cov show ./main -instr-profile=main.profdata

clean:
	rm -f main