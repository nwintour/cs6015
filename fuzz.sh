./fuzz > small_output.txt
./tmain < small_output.txt > small_output.txt
./errorOne > errorOne_output.txt
./tmain < errorOne_output.txt > errorOne_output.txt
./errorTwo > errorTwo_output.txt
./tmain < errorTwo_output.txt > errorTwo_output.txt
./errorThree > errorThree_output.txt
./tmain < errorThree_output.txt > errorThree_output.txt
./errorFour > errorFour_output.txt
./tmain < errorFour_output.txt > errorFour_output.txt
diff small_output.txt small_expected.txt > result_small.txt
diff errorOne_output.txt one_expected.txt > result_one.txt
diff errorTwo_output.txt two_expected.txt > result_two.txt
diff errorThree_output.txt three_expected.txt > result_three.txt
diff errorFour_output.txt four_expected.txt > result_four.txt