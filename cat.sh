#!/bin/bash 
######################
file1=cat.c;
file2=func.c;
print=no;
result_cat=$(cat "$file1")
result_21cat=$(./s21_cat "$file1")
result_cat_b=$(cat -b "$file1")
result_21cat_b=$(./s21_cat -b "$file1")
result_cat_b2=$(cat --number-nonblank "$file1")
result_21cat_b2=$(./s21_cat --number-nonblank "$file1")
result_cat_e=$(cat -e "$file1")
result_21cat_e=$(./s21_cat -e "$file1")
result_cat_v=$(cat -v "$file1")
result_21cat_v=$(./s21_cat -v "$file1")
result_cat_E=$(cat -E "$file1")
result_21cat_E=$(./s21_cat -E "$file1")
result_cat_n=$(cat -n "$file1")
result_21cat_n=$(./s21_cat -n "$file1")
result_cat_n2=$(cat --number "$file1")
result_21cat_n2=$(./s21_cat --number "$file1")
result_cat_s=$(cat -s "$file1")
result_21cat_s=$(./s21_cat -s "$file1")
result_cat_s2=$(cat --squeeze-blank "$file1")
result_21cat_s2=$(./s21_cat --squeeze-blank "$file1")
result_cat_t=$(cat -t "$file1")
result_21cat_t=$(./s21_cat -t "$file1")
result_cat_T=$(cat -T "$file1")
result_21cat_T=$(./s21_cat -T "$file1")
result_cat_file2=$(cat -T "$file1" "$file2")
result_21cat_file2=$(./s21_cat -T "$file1" "$file2")
#####################
if [ "$result_cat" == "$result_21cat" ]; then
        echo "Good:     Test 01:        No args"
else echo "Bad:         Test 01:        No args"
fi
if [ "$print" == "yes" ]; then
        echo "$result_cat"
        echo "$result_21cat"
fi
#################
if [ "$result_cat_b" == "$result_21cat_b" ]; then
        echo "Good:     Test 02:        file    -b"
else echo "Bad:         Test 02:        file    -b"
fi
if [ "$print" == "yes" ]; then
        echo "$result_cat_b"
        echo "$result_21cat_b"
fi
#################
if [ "$result_cat_b2" == "$result_21cat_b2" ]; then
        echo "Good:     Test 03:        file    --number-nonblank"
else echo "Bad:         Test 03:        file    --number-nonblank"
fi
if [ "$print" == "yes" ]; then
        echo "$result_cat_b2"
        echo "$result_21cat_b2"
fi
#################
if [ "$result_cat_e" == "$result_21cat_e" ]; then
        echo "Good:     Test 04:        file    -e"
else echo "Bad:         Test 04:        file    -e"
fi
if [ "$print" == "yes" ]; then
        echo "$result_cat_e"
        echo "$result_21cat_e"
fi
#################
if [ "$result_cat_v" == "$result_21cat_v" ]; then
        echo "Good:     Test 05:        file    -v"
else echo "Bad:         Test 05:        file    -v"
fi
if [ "$print" == "yes" ]; then
        echo "$result_cat_v"
        echo "$result_21cat_v"
fi
#################
if [ "$result_cat_E" == "$result_21cat_E" ]; then
        echo "Good:     Test 06:        file    -E"
else echo "Bad:         Test 06:        file    -E"
fi
if [ "$print" == "yes" ]; then
        echo "$result_cat_E"
        echo "$result_21cat_E"
fi
#################
if [ "$result_cat_n" == "$result_21cat_n" ]; then
        echo "Good:     Test 07:        file    -n"
else echo "Bad:         Test 07:        file    -n"
fi
if [ "$print" == "yes" ]; then
        echo "$result_cat_n"
        echo "$result_21cat_n"
fi
#################
if [ "$result_cat_n2" == "$result_21cat_n2" ]; then
        echo "Good:     Test 08:        file    --number"
else echo "Bad:         Test 08:        file    --number"
fi
if [ "$print" == "yes" ]; then
        echo "$result_cat_n2"
        echo "$result_21cat_n2"
fi
#################
if [ "$result_cat_s" == "$result_21cat_s" ]; then
        echo "Good:     Test 09:        file    -s"
else echo "Bad:         Test 09:        file    -s"
fi
if [ "$print" == "yes" ]; then
        echo "$result_cat_s"
        echo "$result_21cat_s"
fi
#################
if [ "$result_cat_s2" == "$result_21cat_s2" ]; then
        echo "Good:     Test 10:        file    --squeeze-blank"
else echo "Bad:         Test 10:        file    --squeeze-blank"
fi
if [ "$print" == "yes" ]; then
        echo "$result_cat_s2"
        echo "$result_21cat_s2"
fi
#################
if [ "$result_cat_t" == "$result_21cat_t" ]; then
        echo "Good:     Test 11:        file    -t"
else echo "Bad:         Test 11:        file    -t"
fi
if [ "$print" == "yes" ]; then
        echo "$result_cat_t"
        echo "$result_21cat_t"
fi
#################
if [ "$result_cat_T" == "$result_21cat_T" ]; then
        echo "Good:     Test 12:        file    -T"
else echo "Bad:         Test 12:        file    -T"
fi
if [ "$print" == "yes" ]; then
        echo "$result_cat_T"
        echo "$result_21cat_T"
fi
#################
if [ "$result_cat_file2" == "$result_21cat_file2" ]; then
        echo "Good:     Test 13:        Two Files"
else echo "Bad:         Test 13:        Two Files"
fi
if [ "$print" == "yes" ]; then
        echo "$result_cat_file2"
        echo "$result_21cat_file2"
fi
#################
