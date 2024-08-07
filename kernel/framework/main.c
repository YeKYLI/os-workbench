// DO NOT MODIFY: Will be reverted by the Online Judge.

#include <kernel.h>
#include <klib.h>

void pmm_test() {
    pmm->alloc(1);
    pmm->alloc(5);
    pmm->alloc(10);
    pmm->alloc(32);
    pmm->alloc(4096);
    pmm->alloc(4096);
    pmm->alloc(4096);
    while(1);
    // alloc(rand())
}

int main() {
    os->init();
    // mpe_init(os->run);
    mpe_init(pmm_test);
    
    return 1;
}
