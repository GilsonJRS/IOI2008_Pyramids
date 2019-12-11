#include "lib/proj2.h"
#include <stdio.h>
#include <stdlib.h>
#define initialFile 0
#define finalFile 10

int main(){
    Stack *stack_1=initiateStack(1), *stack_to_move=initiateStackWithType(1); 
    FILE *inputF=NULL, *outputF=NULL;
    char inputFile[30],outputFile[30];
    int numBlocks=0;
    for(int i=initialFile;i<=finalFile;i++){
        sprintf(inputFile,"files/inputFiles/pyr%d.in", i);
        sprintf(outputFile,"files/outputFiles/pyr%d.out", i);
        inputF = fopen(inputFile, "r");
        if(inputF != NULL){
            fscanf(inputF, "%d", &numBlocks);
            outputF = fopen(outputFile, "w");
            if(outputF != NULL){
                printf("\nInput file(weight and capacity): files/inputFiles/pyr%d.in\n\n", i);
                readFile(&stack_1, &inputF);
                createStackToMove(stack_1, stack_to_move, &numBlocks);
                invStack(&stack_to_move);
                if(movePyr(stack_to_move, &outputF, numBlocks) && numBlocks <= 21){
                    printf("\noutput file(movements): files/outputFiles/pyr%d.out\n\n---------------------\n", i);
                }else{
                    remove(outputFile);
                    printf("\nO numero de movimentos necessarios para mover essa piramide é superior a 3.000.000\n\n---------------------\n");
                }
                freeStack(stack_1);                
            }else{
                printf("Erro ao criar arquivo pyr%d.out\n", i);
            }
        }else{
            printf("Erro ao abrir arquivo pyr%d.in\n", i);
        }
        fclose(inputF);
        fclose(outputF);
        inputF = NULL;
        outputF = NULL;
    }
    printf("End\n");
}


