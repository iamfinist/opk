#include <stdio.h>
#include <assert.h>
#include "stack.h"

int main() {
    Stack *stack = stack_create();
    stack_push(stack, 128);
    printf("%d\n", stack_peek(stack));
    assert(stack_peek(stack) == 128);

    stack_push(stack, "Never gonna give you up");
    printf("%s\n", stack_peek(stack));
    assert(stack_peek(stack) == "Never gonna give you up");

    stack_pop(stack);
    assert(stack_peek(stack) == 128);

    assert(stack_size(stack) == 2);

    stack_destroy(stack);

    return 0;
}