#include <stdlib.h>

typedef struct{
    long int weight, capacity, repeat; 
    int num;
}data;

struct node{
    data value;
    struct node *prox;
};
typedef struct node No;

typedef struct{
    int /*stackCapacity,*/numBlocks ,firstWeight, totalWeight, type;
    No *prox;
}Stack;

/* 
    function to initiate the stack
    param: type os stack
        1 = initial stack
        2 = auxiliary stack
        3 = destiny stack
    return: stack
*/
Stack *initiateStackWithType(int type);

/*
    function to initiate the stack
    return: stack
*/
Stack *initiateStack();

/*
    function to alloc a node
    param: data
    return: node with data
*/
No *alloc(data value);

/*
    function to invert a stack
    param: stack in wrong order
*/
void invStack(Stack **stack);

/*
    function to push a node in stack
    param: stack and data 
*/
void push(Stack *stack, data value);

/*
    function to remove a stack's node
    param: stack
    return: data of stack's top node
*/
data pop(Stack *stack);

/*
    function to consult the top os stack, without remove
    param: stack
    return: data of stack's top node
*/
data stackTop(Stack **stack);

/*
    function to consult the top os stack, without remove
    param: stack
    return: data of stack's top node
*/
int compareStack(Stack *Stack_1, Stack *stack_2);

/*
    function to copy a stack
    param: stack
    return: pointer to a new stack
*/
Stack *copyStack(Stack *Stack_1);

/*
    function to verify if stack is empty
    param: stack
    return: 1 = empty, 0 = not empty
*/
int isEmpty(Stack *stack);

/*
    function to free a stack
    param: stack
*/
void freeStack(Stack *stack);

/*
    function to free nodes of a stack
    param: prox of stack head
*/
No *freeNodes(No *no);