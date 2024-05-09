#ifndef MWRITE_H
#define MWRITE_H

#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

typedef struct
{
    size_t size;
    char data[];
} mchunk;

void* mwrite(size_t size)
{
    mchunk* mem = mmap(NULL, sizeof(mchunk) + size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mem == MAP_FAILED)
    {
        return NULL;
    }
    mem->size = size;
    return mem->data;
}

void mfree(void* ptr)
{
    mchunk* mem = (mchunk*)((char*)ptr - offsetof(mchunk, data));
    munmap(mem, sizeof(mchunk) + mem->size);
    ptr = NULL;
}

#endif // MWRITE_H
