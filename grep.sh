#!/bin/bash 
######################
file1=grep.c;
file2=print.c;
file_arg=arg.txt;
looking_string=[a-z].;
looking_string2=a;
print=no;
result_grep_e=$(grep -e "$looking_string" "$file1")
result_grep3_e=$(./s21_grep -e "$looking_string" "$file1")
result_grep_i=$(grep -i "$looking_string" "$file1")
result_grep3_i=$(./s21_grep -i "$looking_string" "$file1")
result_grep_v=$(grep -v "$looking_string" "$file1")
result_grep3_v=$(./s21_grep -v "$looking_string" "$file1")
result_grep_c=$(grep -c "$looking_string" "$file1")
result_grep3_c=$(./s21_grep -c "$looking_string" "$file1")
result_grep_l=$(grep -l "$looking_string" "$file1")
result_grep3_l=$(./s21_grep -l "$looking_string" "$file1")
result_grep_n=$(grep -n "$looking_string" "$file1")
result_grep3_n=$(./s21_grep -n "$looking_string" "$file1")
result_grep_h=$(grep -h "$looking_string" "$file1" "$file2")
result_grep3_h=$(./s21_grep -h "$looking_string" "$file1" "$file2")
result_grep_s=$(grep -s "$looking_string" "$file1")
result_grep3_s=$(./s21_grep -s "$looking_string" "$file1")
result_grep_c=$(grep -c "$looking_string" "$file1")
result_grep3_c=$(./s21_grep -c "$looking_string" "$file1")
result_grep_f=$(grep -f "$file_arg" "$file1")
result_grep3_f=$(./s21_grep -f "$file_arg" "$file1")
result_grep_o=$(grep -o "$looking_string" "$file1")
result_grep3_o=$(./s21_grep -o "$looking_string" "$file1")
result_grep_iv=$(grep -iv "$looking_string" "$file1")
result_grep3_iv=$(./s21_grep -iv "$looking_string" "$file1")
result_grep_in=$(grep -in "$file2" "$file1")
result_grep3_in=$(./s21_grep -in "$file2" "$file1")
result_grep_cl=$(grep -cl "$looking_string" "$file1")
result_grep3_cl=$(./s21_grep -cl "$looking_string" "$file1")
result_grep_nh=$(grep -nh "$looking_string" "$file1")
result_grep3_nh=$(./s21_grep -nh "$looking_string" "$file1")
result_grep_e3=$(grep -e "$looking_string" -e "2" -e "3" "$file1")
result_grep3_e3=$(./s21_grep -e "$looking_string" -e "2" -e "3" "$file1")
result_grep_ie=$(grep -ie "$looking_string" "$file1")
result_grep3_ie=$(./s21_grep -ie "$looking_string" "$file1")
result_grep_no=$(grep -no "$looking_string" "$file1")
result_grep3_no=$(./s21_grep -no "$looking_string" "$file1")
result_grep_oc=$(grep -oc "$looking_string" "$file1" "$file2")
result_grep3_oc=$(./s21_grep -oc "$looking_string" "$file1" "$file2")
#####################
if [ "$result_grep_test" == "$result_grep3_test" ]; then
	echo "TEST 100: GOOD"
else echo "TEST 100: BAD"
fi
if [ "$result_grep_test2" == "$result_grep3_test2" ]; then
	echo "TEST 200: GOOD"
else echo "TEST 200: BAD"
fi
#####################
if [ "$result_grep_e" == "$result_grep3_e" ]; then
	echo "TEST 01: -e: GOOD"
else echo "TEST 01: -e: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_e"
        echo "$result_grep3_e" 
        fi
####################
if [ "$result_grep_i" == "$result_grep3_i" ]; then
        echo "TEST 02: -i: GOOD"
else echo "TEST 02: -i: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_i"
        echo "$result_grep3_i" 
        fi
###################
if [ "$result_grep_v" == "$result_grep3_v" ]; then
        echo "TEST 03: -v: GOOD"
else echo "TEST 03: -v: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_v"
        echo "$result_grep3_v" 
        fi
##################
if [ "$result_grep_c" == "$result_grep3_c" ]; then
        echo "TEST 04: -c: GOOD"
else echo "TEST 04: -c: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_c"
        echo "$result_grep3_c"
        fi
#################
if [ "$result_grep_l" == "$result_grep3_l" ]; then
        echo "TEST 05: -l: GOOD"
else echo "TEST 05: -l: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_l"
        echo "$result_grep3_l" 
        fi
#################
if [ "$result_grep_n" == "$result_grep3_n" ]; then
        echo "TEST 06: -n: GOOD"
else echo "TEST 06: -n: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_n"
        echo "$result_grep3_n" 
        fi
#################
if [ "$result_grep_h" == "$result_grep3_h" ]; then
        echo "TEST 07: -h: GOOD"
else echo "TEST 07: -h: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_h"
        echo "$result_grep3_h" 
        fi
#################
if [ "$result_grep_s" == "$result_grep3_s" ]; then
        echo "TEST 08: -s: GOOD"
else echo "TEST 08: -s: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_s"
        echo "$result_grep3_s" 
        fi
#################
if [ "$result_grep_f" == "$result_grep3_f" ]; then
        echo "TEST 09: -f: GOOD"
else echo "TEST 09: -f: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_f"
        echo "$result_grep3_f" 
        fi
#################
if [ "$result_grep_o" == "$result_grep3_o" ]; then
        echo "TEST 10: -o: GOOD"
else echo "TEST 10: -o: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_o"
        echo "$result_grep3_o" 
        fi
#################
if [ "$result_grep_iv" == "$result_grep3_iv" ]; then
        echo "TEST 11: -iv: GOOD"
else echo "TEST 11: -iv: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_iv"
        echo "$result_grep3_iv" 
        fi
#################
if [ "$result_grep_in" == "$result_grep3_in" ]; then
        echo "TEST 12: -in: GOOD"
else echo "TEST 12: -in: BAD"
fi
if [ "$print" == "yes" ]; then
	echo "$result_grep_in"
	echo "$result_grep3_in" 
fi
#################
if [ "$result_grep_cl" == "$result_grep3_cl" ]; then
        echo "TEST 13: -cl: GOOD"
else echo "TEST 13: -cl: BAD"
fi
if [ "$print" == "yes" ]; then
	echo "$result_grep_cl"
	echo "$result_grep3_cl"
fi
#################
if [ "$result_grep_nh" == "$result_grep3_nh" ]; then
        echo "TEST 14: -nh: GOOD"
else echo "TEST 14: -nh: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_nh"
        echo "$result_grep3_nh"
fi
#################
if [ "$result_grep_e3" == "$result_grep3_e3" ]; then
        echo "TEST 15: -e -e -e: GOOD"
else echo "TEST 15: -e -e -e: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_e3"
        echo "$result_grep3_e3"
fi
#################
if [ "$result_grep_ie" == "$result_grep3_ie" ]; then
        echo "TEST 16: -ie: GOOD"
else echo "TEST 16: -ie: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_ie"
        echo "$result_grep3_ie"
fi
#################
if [ "$result_grep_no" == "$result_grep3_no" ]; then
        echo "TEST 17: -no: GOOD"
else echo "TEST 17: -no: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_no"
        echo "$result_grep3_no"
fi
#################
if [ "$result_grep_oc" == "$result_grep3_oc" ]; then
        echo "TEST 18: -oc: GOOD"
else echo "TEST 18: -oc: BAD"
fi
if [ "$print" == "yes" ]; then
        echo "$result_grep_no"
        echo "$result_grep3_no"
fi
#################