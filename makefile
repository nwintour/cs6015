all: assignment3

assignment3: main.cpp
	clang++ -std=c++14 main.cpp -o main

make: all
	clang++ -std=c++14 main.cpp -o main

configure:
	./configure

coverage: main.cpp
	clang++ -fprofile-instr-generate -fcoverage-mapping main.cpp -o main
	LLVM_PROFILE_FILE="main.profraw" ./main < full_input.txt > test_output.txt
	xcrun llvm-profdata merge -sparse main.profraw -o main.profdata
	xcrun llvm-cov show ./main -instr-profile=main.profdata main.cpp > coverage.txt

fuzzer:
	for run in {1..1000}; do ./fuzz.sh; done

test: all
	./test.sh

clean:
	rm -f main