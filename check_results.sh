# EE599 - Spring 2019
# Lab3 - shell script
# Instructor: Shahin Nazarian
# Author: Junting Zhang

g++ -o pancake_sort.o EE599_Lab3_*.cpp
./pancake_sort.o < input.txt

diff output.txt output_golden.txt > result.txt
if [ -s result.txt ]
then
	echo "Test Failed!"

else
	echo "Test Passed!"
fi
rm result.txt

rm pancake_sort.o