#ifndef _MYMALLOC_H
#define _MYMALLOC_H

#include <stdio.h>
#include <stdlib.h>


#define malloc(x) mymalloc(x)
#define free(x) myfree(x)

void * mymalloc(size_t size);
void* myfree(char *a);


#endif
