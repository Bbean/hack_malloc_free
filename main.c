#include <stdio.h>
#include <stdlib.h>
int main(){
    void *p = malloc(1000);
    if (p !=  NULL) {
	printf("malloc ok! addr:%p\n",p);
        free(p); 
	printf("free ok!\n");
    }
    return 0;
}
