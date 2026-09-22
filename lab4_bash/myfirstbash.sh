#! /bin/bash

# name="DaeKyu" #no space!! 변수 반들 때 등호 양 옆 스페이스하면 안 됨.

read -p "Enter tour name: " name

echo "Helllo world $name!" #${name} <- 이렇게 해도 됨.
echo "Nice to meet ${name}~" #" "가 아닌 ' '을 하면 변수가 해석되지 않음.