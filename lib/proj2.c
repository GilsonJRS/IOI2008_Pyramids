#include "proj2.h"
#include <stdlib.h>

void readFile(Stack **stack_1, FILE **inputFile){
    data fileData;
    while(!feof(*inputFile)){
        fscanf(*inputFile, "%ld %ld", &(fileData.weight), &(fileData.capacity));
        //printf("%d %d\n",(fileData.weight), (fileData.capacity));
        push(*stack_1, fileData);
    }
    if((*stack_1)->prox != NULL) invStack(stack_1);
}

int moveBlock(Stack **origin, Stack **destiny){
    if((*origin)->prox == NULL) return 0;
    data originBlock = stackTop(origin), a;
    if((*destiny)->prox == NULL){
        push(*destiny, originBlock);
        //printf("origin capacity: %d\n", originBlock.capacity);
        //(*destiny)->stackCapacity += originBlock.capacity;
        pop(*origin);
        //print on file the movement >>> MODIFY
        printf("%d %d\n", (*origin)->type, (*destiny)->type);
        return 1;
    }else if(verifyCapacity(*destiny, originBlock.weight/*(*destiny)->stackCapacity >= originBlock.weight && (((a = stackTop(origin)).capacity != 0 && a.weight != 0))*/)==1){
        //printf("origin capacity: %d\n", originBlock.capacity);
        push(*destiny, originBlock);
        //(*destiny)->stackCapacity -= originBlock.weight;
        pop(*origin);
        //print on file the movement >>> MODIFY
        printf("%d %d\n", (*origin)->type, (*destiny)->type);
        return 1;
    }
    return 0;
}

int movePyr(Stack *stack_1, FILE **outputFile, int numBlocks){
    Stack *stack_2=initiateStackWithType(2), *stack_3=initiateStackWithType(3);
    data a;
    int numMovs=0;
    //Stack *stack_2=initiateStack(), *stack_3=initiateStack();
    moveStyleHanoi(&numMovs, numBlocks, stack_1, stack_2, stack_3, outputFile);
    if(numMovs <= 3000000){
        printf("Stack 3(destiny): \n");
        No *no = stack_3->prox;
        while(no!=NULL){
            if(no->value.repeat > 0){
                printf("%ld %ld (more than one block treated as one)\n", no->value.weight, no->value.capacity);
            }else{
                printf("%ld %ld\n", no->value.weight, no->value.capacity);
            }
            no = no->prox;
        }
        freeStack(stack_3);
        return 1;
    }else{
        freeStack(stack_3);
        return 0;
    }
}

void moveStyleHanoi(int *numMovs, int n, Stack *origin,Stack *auxiliary,Stack *destiny, FILE **outputFile){
    if(n == 1){
        data block = pop(origin);
        if(verifyCapacity(destiny, block.weight)){
            //printf("%d %d\n", (origin)->type, (destiny)->type);
            for(int i=0;i<=block.repeat;i++){
                *numMovs = *numMovs + 1;
                if(*numMovs > 3000000){return;}
                fprintf(*outputFile, "%d %d\n", (origin)->type, (destiny)->type);
            }
            push(destiny, block);
        }
        return;
    }else{
        moveStyleHanoi(numMovs,n-1, origin, destiny, auxiliary, outputFile);
        data block = pop(origin);
        if(verifyCapacity(destiny, block.weight)){
            //printf("%d %d\n", (origin)->type, (destiny)->type);
            for(int i=0;i<=block.repeat;i++){
                *numMovs = *numMovs + 1;
                if(*numMovs > 3000000){return;}
                fprintf(*outputFile, "%d %d\n", (origin)->type, (destiny)->type);
            }
            push(destiny, block);
        }
        moveStyleHanoi(numMovs, n-1, auxiliary, origin, destiny, outputFile);
    }
}

int verifyCapacity(Stack *stack, int weight){
    No *aux = stack->prox;
    unsigned long int sumWeight = weight;
    while(aux!=NULL){
        if(sumWeight > aux->value.capacity){
            return 0;
        } 
        sumWeight += aux->value.weight;
        aux = aux->prox;
    }
    return 1; 
}

int verifyOrder(Stack *stack){
    No *aux = stack->prox;
    if(aux->prox == NULL) return 1;
    int i = aux->value.num;
    while(aux->prox!=NULL){
        if((i - aux->prox->value.num) != 1) return 0;
        aux = aux->prox;
    }
    return 1;
}

void createStackToMove(Stack *stack_1, Stack *new_stack, int *numBlocks){
    No *aux = stack_1->prox->prox, *ref = stack_1->prox;
    int capacityRef = ref->value.capacity, sumW=0, sumC=0;
    data data_new;
    int i=0, num=1;
    while(aux->prox!=NULL){
        //printf("%d\n", i);
        if(aux->value.weight + sumW <= capacityRef){
            sumC += aux->value.capacity;
            sumW += aux->value.weight;
            i++;
        }else{
            data_new.weight = sumW + ref->value.weight;
            data_new.capacity = sumC + ref->value.capacity;
            data_new.repeat = i;
            push(new_stack, data_new);
            ref = aux;
            i = 0;
            sumW = 0;
            sumC = 0;
            capacityRef = ref->value.capacity;
            num++;
            if(ref->prox->prox == NULL){
                data_new.capacity = ref->value.capacity;
                data_new.weight = ref->value.weight;
                data_new.repeat = 0;
                push(new_stack, data_new);
                num++;
            }
        }
        aux = aux->prox;
    }   
    if(sumW != 0 && sumC != 0){
        data_new.capacity = sumC;
        data_new.weight = sumW;
        data_new.repeat = i;
        push(new_stack, data_new);
        num++;
    }
    data_new.capacity = aux->value.capacity;
    data_new.weight = aux->value.weight;
    data_new.repeat = 0;
    push(new_stack, data_new);
    *numBlocks = num;
}