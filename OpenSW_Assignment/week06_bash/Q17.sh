#! /bin/bash

file_wordcnt()
{
    FILE=$(ls *.txt)
    for n in $FILE
    do
        echo "$n 파일의 단어는 $(cat $n | wc -w) 개 입니다."
    done
}

file_wordcnt