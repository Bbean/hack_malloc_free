#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

#define printf(...)
void *malloc(size_t size) {
	printf("call my malloc\n");
	void* (*ori_malloc)(size_t size);
	if (dlerror() != NULL){
		printf("dlsym malloc error\n");
		return NULL;
	}
	printf("call ori malloc now\n");
	ori_malloc = dlsym(RTLD_NEXT, "malloc");
	return (*ori_malloc)(size);

}

void free(void *paddr) {
	printf("call my free\n");
	void (*ori_free)(void *p);
	if (dlerror() != NULL){
		printf("dlsym free error\n");
		return;
	}
	printf("call ori free now\n");
	ori_free = dlsym(RTLD_NEXT, "free");
	return (*ori_free)(paddr);
}
