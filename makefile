all: assignment3

assignment3: main.cpp
	clang++ -std=c++14 main.cpp -o main

make: all
	clang++ -std=c++14 main.cpp -o main

configure:
	./configure

coverage:
	clang++ -fprofile-instr-generate -fcoverage-mapping main.cpp -o main
	LLVM_PROFILE_FILE="main.profraw" ./main << coverage.txt
	xrun llvm-profdata merge -sparse main.profraw -o main.profdata
	xrun llvm-cov show ./main -instr-profile=main.profdata

fuzzer:
	for run in {1..1000}; do ./numberGenerator.sh; done

test: all
	./test.sh

clean:
	rm -f main