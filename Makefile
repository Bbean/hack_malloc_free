all: libhack_malloc_free_lib.so main

libhack_malloc_free_lib.so:hack_malloc_free_lib.c
	gcc -fPIC hack_malloc_free_lib.c --shared -o libhack_malloc_free_lib.so -ldl

main: main.c
	gcc main.c -o main -L. -lhack_malloc_free_lib

clean:
	rm main libhack_malloc_free_lib.so
