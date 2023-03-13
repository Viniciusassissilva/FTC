#include<stdio.h>
#include <stdlib.h>

int Menu(){

    int input;

    printf("Insira a opção que deseja: \n");
    printf("1 - Visualizacao \n");
    printf("2 - Complemento \n");
    printf("3 - Intersecao ou Uniao \n");
    printf("4 - Minimizacao \n");
    printf("5 - Reconhecimento de Palavra \n");
    scanf("%d", &input);  

    return input;
}



int main(void){
    
    int input;
    input = Menu();
    

    return 0;
}