#ifndef STACKS_H_
#define STACKS_H_

#include <stdlib.h>

typedef struct {
    unsigned* elements;
    size_t m;
} Stack;

extern unsigned MaxSumNStack(Stack* stacks, size_t n);

#endif // !STACKS_H_
