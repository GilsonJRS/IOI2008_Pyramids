#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack *initiateStackWithType(int type){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->prox = NULL;
    stack->firstWeight = 0;
    stack->totalWeight = 0;
    stack->type = type;
    //stack->stackCapacity = 0;
    return stack;
}

Stack *initiateStack(){
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->prox = NULL;
    stack->firstWeight = 0;
    stack->totalWeight = 0;
    stack->type = 0;
    //stack->stackCapacity = 0;
    return stack;
}

No *alloc(data value){
    No *no = (No *)malloc(sizeof(No));
    
    no->value.weight = value.weight;
    no->value.capacity = value.capacity;
    no->value.num = value.num;
    no->value.repeat = value.repeat;
    no->prox = NULL;
    
    return no;
}
void push(Stack *stack, data value){
    if(stack->prox == NULL){
        No *no_aux = alloc(value);
        stack->prox = no_aux;
        return;
    }
    No *no_aux = alloc(value);
    no_aux->prox = stack->prox;
    stack->prox = no_aux;
}

data pop(Stack *stack){
    if(stack->prox != NULL){
        data value;
        No *no_aux;

        value.weight = (stack->prox)->value.weight;
        value.capacity = (stack->prox)->value.capacity;
        value.num = (stack->prox)->value.num;
        value.repeat = (stack->prox)->value.repeat;

        no_aux = stack->prox;
        stack->prox = (stack->prox)->prox;
        free(no_aux);
        
        return value;
    }else{
        data value = {0,0,0};
        return value;
    }
}

void invStack(Stack **stack){
    Stack *stack_aux = initiateStackWithType(1);
    data aux = pop(*stack);
    int i=1;
    //(*stack)->stackCapacity = aux.capacity;
    while(aux.capacity != 0 || aux.weight !=0){
        aux.num = i;
        push(stack_aux, aux);
        aux = pop(*stack);
        i++;
        //(*stack)->stackCapacity -= aux.capacity;
    };
    free(*stack);
    *stack = stack_aux;
    //printf("asdfadsf: %d", stack_aux->prox->value.num);
}

data stackTop(Stack **stack){
    if((*stack)->prox != NULL){
        return ((*stack)->prox)->value;
    }else{
        data a = {0,0};
        return a;
    }
}

int isEmpty(Stack *stack){
    if(stack->prox == NULL){
        return 1;
    }
    return 0;
}

int compareStack(Stack *stack_1, Stack *stack_2){
    if(stack_1->prox == NULL || stack_2->prox == NULL) return 0;
    No *aux = (stack_1)->prox, *aux2 = (stack_2)->prox;
    while(aux!=NULL){
        if(aux->value.capacity != aux2->value.capacity || aux->value.weight != aux2->value.weight){
            return 0;//false
        }
        aux = aux->prox;
        aux2 = aux2->prox;
        if(aux2 == NULL && aux != NULL){
            return 0;//false
        }
    }
    return 1;//true
}

Stack *copyStack(Stack *stack_1){
    Stack *copy = initiateStackWithType(1);
    No *aux = (stack_1)->prox;
    while(aux!=NULL){
        push(copy, aux->value);
        aux = aux->prox;
    }
    invStack(&copy);
    return copy;
}

void freeStack(Stack *stack){
    if(stack->prox != NULL){
        stack->prox = freeNodes(stack->prox);
        return;
    }
    return;
}

No *freeNodes(No *no){
    if(no == NULL){
        return NULL;
    }
    freeNodes(no->prox);
    free(no);
    return NULL;
}