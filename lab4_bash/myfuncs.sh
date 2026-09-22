#! /bin/bash

test_variable()
{
    name="DaeKyu"
    echo "Hello $name"
}

test_params()
{
    echo $1
    echo $2
    echo $3
    echo $* # $@
    echo $#
}

test_for()
{
    for n in 10 20 30; do
    echo $n
    done

    for x in $@; do
    echo $x
    done
}

print_file_lines()
{
    files=$(ls)
    for f in $files; do
    line_num=$(cat $f | wc -l)
    echo $f $line_num

    done
}



sum_from_1_to_n()
{
    n_final=$1
    sum=0
    for i in $(seq 1 $n_final); do
    sum=$(($sum + $i))
    done
    echo $sum
}

test_cond()
{
    sum=0
    for n in $(seq 100); do
        if [ $((n % 2)) -eq 0 ]; then
            sum=$(($sum + n))
        else
            sum=$sum
            fi
    done
    echo $sum
}

# print_long_words_starting_with_c()
# {
#     for n in $(cat /usr/share/dict/words | grep '^c'); do
#         if [ $(echo $n | wc -c) -gt 20 ]; then
#         echo $n
#         fi
#     done
# }

print_long_words_starting_with_c()
{
    words=$(cat /usr/share/dict/words | grep ^c)
    for n in $words; do
        word_len=$(echo $n | wc -c)
        if [ $word_len -ge 20 ]; then
        echo $n $word_len
        fi
    done
}

print_long_words_starting_with_c

# test_cond

# for n in {a..z}; do
#     echo $n
# done

# sum_from_1_to_n 100


# num_a="100"
# num_b=2
# sum=$(( num_a % num_b )) # +, -, *, /, %
# echo $sum

# print_file_lines

# files=$(ls | wc -l)
# echo $files

# test_for daekyu heechul snagho rddds

# test_params 10 20 30

# 함수 바깥에 있을 때

# echo $0
# echo $1
# echo $2
# echo $3
# echo $@
# echo $#

# test_variable