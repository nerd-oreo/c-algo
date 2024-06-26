#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <common/common.h>
#include <stack/stack.h>

void stack_test();

int main()
{
    stack_test();

    return 0;
}

void stack_test()
{
    srand(time(NULL));
    int nItem = 5;

    // Test ArrayStack_init
    ArrayStack *stack = ArrayStack_init();

    // Test ArrayStack_push
    for (int i = 0; i < nItem; i++)
    {
        int *data = (int *)malloc(sizeof(int));
        *data = random_number(1, 100);
        ArrayStack_push(stack, data);
    }

    // Test ArrayStack_debug
    ArrayStack_debug(stack, 'i');

    // Test ArrayStack_pop
    do
    {
        int *data = (int *)ArrayStack_pop(stack);
        printf("\ndata from pop(): %d\n", *data);
        ArrayStack_debug(stack, 'i');
    } while (stack->size != 0);

    // Test ArrayStack_push
    for (int i = 0; i < nItem; i++)
    {
        int *data = (int *)malloc(sizeof(int));
        *data = random_number(1, 100);
        ArrayStack_push(stack, data);
    }

    // Test ArrayStack_peek
    ArrayStack_debug(stack, 'i');
    int *data = ArrayStack_peek(stack);
    printf("\ndata from peek(): %d\n", *data);
}