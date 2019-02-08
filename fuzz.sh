./fuzz > small_input.txt
./tmain < small_input.txt > small_output.txt
./errorOne > errorOne_input.txt
./tmain < errorOne_input.txt > errorOne_output.txt
./errorTwo > errorTwo_input.txt
./tmain < errorTwo_input.txt > errorTwo_output.txt
./errorThree > errorThree_input.txt
./tmain < errorThree_input.txt > errorThree_output.txt
./errorFour > errorFour_input.txt
./tmain < errorFour_input.txt > errorFour_output.txt
diff small_output.txt small_expected.txt > result_small.txt
diff errorOne_output.txt one_expected.txt > result_one.txt
diff errorTwo_output.txt two_expected.txt > result_two.txt
diff errorThree_output.txt three_expected.txt > result_three.txt
diff errorFour_output.txt four_expected.txt > result_four.txt