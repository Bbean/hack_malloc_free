all: libhack_malloc_free_lib.so main main-ori

libhack_malloc_free_lib.so:hack_malloc_free_lib.c
	gcc -fPIC hack_malloc_free_lib.c --shared -g -o libhack_malloc_free_lib.so -ldl

main: main.c
	gcc main.c -o main -L. -lhack_malloc_free_lib -g

main-ori: main.c
	gcc main.c -o main-ori

clean:
	rm main libhack_malloc_free_lib.so main-ori
