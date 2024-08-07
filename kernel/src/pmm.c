#include <common.h>

int locked = 0;

static void lock() {
    while(atomic_xchg(&locked, 1));
}

static void  unlock() {
    atomic_xchg(&locked, 0);
}

#define atomic \
    for (int __i = (lock(), 0); __i < 1; __i++, unlock())

static void *kalloc(size_t size) {
    // TODO
    // You can add more .c files to the repo.

    char* ret;
    static void* pos;
    atomic {
        
        if(!pos) pos = heap.start;

        int sz = 1;
        while(sz < size) {
            sz *= 2;
        }

        while ((intptr_t)pos % sz != 0) {
            pos ++;
        }

        ret = pos;
        pos += sz;

        panic_on(pos > heap.end, "Heap Full");

    }
    return ret;
}

static void kfree(void *ptr) {
    // TODO
    // You can add more .c files to the repo.
}

void alloc(int sz) {
    uintptr_t a = (uintptr_t)kalloc(sz);
    uintptr_t align = a & -a;
    printf("Alloc %d -> %p align = %d\n", sz, a, align);
    assert(a && align >= sz);
}

static void pmm_init() {
    uintptr_t pmsize = (
        (uintptr_t)heap.end
        - (uintptr_t)heap.start
    );

    printf(
        "Got %d MiB heap: [%p, %p)\n",
        pmsize >> 20, heap.start, heap.end
    );
}

MODULE_DEF(pmm) = {
    .init  = pmm_init,
    .alloc = kalloc,
    .free  = kfree,
};
