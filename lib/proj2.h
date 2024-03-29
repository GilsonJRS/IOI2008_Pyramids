#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
/*
    function to read a parameter file from
    a pyramid and save it to a stack
    param: stack_1(origin stack) and the input file
*/
void readFile(Stack **stack_1, FILE **inputFile);

/*
    function to move the pyramid from origin
    to destiny and print it on a file
    param: origin stack, output file and the num of blocks
    return: 1 if the pyr is moved, 0 otherwise
*/
int movePyr(Stack *stack_1, FILE **outputFile, int numBlocks);

/*
    function to move a pyramid's block from origin
    to destiny.
    param: origin stack and destiny stack
*/
int moveBlock(Stack **origin, Stack **destiny);

/*
    function to move a pyramid's with hanoi algorithm
    param: origin stack and destiny stack
*/
void moveStyleHanoi(int *numMovs, int n, Stack *origin,Stack *auxiliary,Stack *destiny, FILE **outputFile);

/*
    function to check if stack supports one more
    block
    param: origin stack and destiny stack
*/
int verifyCapacity(Stack *stack, int weight);

/*
    function to create a stack with group 
    of blocks
    param: pointer to original stack, new stack, and the num of blocks
*/
void createStackToMove(Stack *stack_1, Stack *new_stack, int *numBlocks);