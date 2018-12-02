clang -c headers/file.c -o object/file.o
clang -c headers/list.c -o object/list.o
clang -c headers/struct.c -o object/struct.o
clang -c main.c -o object/main.o

clang -o exo2.out object/main.o object/file.o object/list.o object/struct.o
