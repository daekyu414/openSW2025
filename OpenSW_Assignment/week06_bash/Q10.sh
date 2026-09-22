#!/bin/bash

print_param()
{
    echo "script name: $0"
    echo "first name: $1"
    echo "second name: $2"
    echo "all params: $@"
    echo "the number of params: $#"
}

print_param "Hello" "World" "!"