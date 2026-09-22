#! /bin/bash

factorial()
{
    fac=1
    for n in $(seq 1 $NUM)
    do
        fac=$(( fac * $n))
    done

    result=$fac    

    echo "Factorial of $1 is $result"
}

read -p "Enter a number : " NUM
factorial $NUM