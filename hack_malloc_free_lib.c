#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
void *malloc(size_t size) {
	printf("call my malloc\n");
	void* (*ori_malloc)(size_t size);
	if (dlerror() != NULL){
		printf("dlsym malloc error\n");
		return NULL;
	}
	ori_malloc = dlsym(RTLD_NEXT, "malloc");
	return ori_malloc(size);

}

void free(void *paddr) {
	printf("call my free\n");
	void (*ori_free)(void *p);
	if (dlerror() != NULL){
		printf("dlsym free error\n");
		return;
	}
	ori_free = dlsym(RTLD_NEXT, "free");
	return ori_free(paddr);
}
