./fuzz > small_input.txt
./tmain < small_input.txt > small_output.txt
diff small_output.txt small_expected.txt > result_small.txt
./errorOne > errorOne_input.txt
./tmain < errorOne_input.txt > errorOne_output.txt
diff errorOne_output.txt one_expected.txt > result_one.txt
./errorTwo > errorTwo_input.txt
./tmain < errorTwo_input.txt > errorTwo_output.txt
diff errorTwo_output.txt two_expected.txt > result_two.txt
./errorThree > errorThree_input.txt
./tmain < errorThree_input.txt > errorThree_output.txt
diff errorThree_output.txt three_expected.txt > result_three.txt
./errorFour > errorFour_input.txt
./tmain < errorFour_input.txt > errorFour_output.txt
diff errorFour_output.txt four_expected.txt > result_four.txt