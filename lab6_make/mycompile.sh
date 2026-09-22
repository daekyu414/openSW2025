# /bin/bash

gcc -c src/func1.c -o obj/func1.o -I./include
gcc -c src/func2.c -o obj/func2.o -I./include
gcc -c src/main.c -o obj/main.o -I./include
gcc obj/func1.o obj/func2.o obj/main.o -o bin/myapp