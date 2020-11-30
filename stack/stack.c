#include <stdio.h>
#include "stack.h"

#define INIT_SIZE 10
#define MULTIPLIER 2
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

struct Stack {
    Pointer* data;
    size_t size;
    size_t top;
};



Stack* stack_create() {
    Stack* pstack = malloc(sizeof(Stack));
    if (pstack == NULL)
        exit(OUT_OF_MEMORY);
    pstack->size = INIT_SIZE;
    pstack->data = malloc(pstack->size * sizeof(Pointer));
    if (pstack->data == NULL) {
        free(pstack);
        exit(OUT_OF_MEMORY);
    }
    pstack->top = 0;
    return pstack;
}

void stack_resize(Stack* pstack) {
    pstack->size *= MULTIPLIER;
    pstack->data = realloc(pstack->data, pstack->size * sizeof(Pointer));
    if (pstack->data == NULL) {
        exit(STACK_OVERFLOW);
    }
}

void stack_destroy(Stack *pstack) {
    free(pstack->data);
    free(pstack);
}


void stack_push(Stack *pstack, Pointer value) {
    if (pstack->top >= pstack->size) {
        stack_resize(pstack);
    }
    pstack->data[pstack->top] = value;
    pstack->top++;
}

size_t stack_size(Stack* pstack) {
    return pstack->top+1;
}

Pointer stack_pop(Stack *pstack) {
    if (pstack->top == 0) {
        exit(STACK_UNDERFLOW);
    }
    pstack->top--;
    if (pstack->top < pstack->size / 4) {
        pstack->size /= 2;
        realloc(pstack->data, pstack->size * sizeof(Pointer));
    }
    return pstack->data[pstack->top];
}
int stack_peek(Stack* pstack) {
    if (pstack->top <= 0) {
        exit(STACK_UNDERFLOW);
    }
    return pstack->data[pstack->top - 1];
}
