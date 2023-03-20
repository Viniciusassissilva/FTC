#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void exer_1(){printf("exer_1");}
void exer_2(){printf("exer_1");}
void exer_3(){printf("exer_1");}
void exer_4(){printf("exer_1");}
void exer_5(){printf("exer_1");}

struct Node {
    char* data;
    struct Node* next;
};

// Função para inserir um nó no início da lista
void InserirNode(struct Node** headRef, char* data) {
    // Criando um novo nó
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    // Alocando memória para o valor do novo nó
    newNode->data = (char*) malloc(strlen(data) + 1);

    // Copiando o valor para o novo nó
    strcpy(newNode->data, data);

    // Definindo o próximo nó
    newNode->next = *headRef;

    // Atualizando o ponteiro da cabeça da lista
    *headRef = newNode;
}

// Função para liberar a memória alocada para a lista
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%s", head->data);
        head = head->next;
    }
    printf("\n");
}

void MudarHead(struct Node** headRef, char* newValue) {
    
    char oldLine[100];
    strcpy(oldLine, (*headRef)->data);
    strcpy(oldLine, oldLine);

    char copyOldLine[100];
    strcpy(copyOldLine, oldLine);

    char separador[1] = " ";
    char espaco[1];
    strcpy(espaco, separador);
    //strcpy(copyOldLine, espaco);

    char newInfo[100];
    strcpy(newInfo, newValue);

    //printf("%s", strcat(copyOldLine, newInfo)); 
    printf("%s", copyOldLine); 

    (*headRef)->data = newValue;

}

int Menu(){
    int condition=1, option;


    while (condition == 1)
    {
        printf("escolha uma opcao: \n");
        scanf("%d", option);

        switch (option){
        case 1:
            exer_1();
            break;
        case 2:
            exer_2();
            break;
        case 3:
            exer_3();
            break;
        case 4:
            exer_4();
            break;
        case 5:
            exer_5();
            break;
        case 6:
            condition = 0;
            break;
        default:
            break;
        }
    }

}

void Visualizacao(){

    struct Node* head = NULL;
    int contador = 0, qntEstados, qntAlfabeto, qntTransicoes, qntEstadosFinais;
    FILE *entrada;
    FILE *saida;

    char linha[100];
    char texto[100];

    saida = fopen("D:/FTC/teste.txt", "w");
    entrada = fopen("D:/FTC/afd.txt", "r");

    fprintf(saida,  "diagph finite_state_machine { \n"
                    "fontname=\"Heletiva ,Arial, sans-serif\" \n"
                    "node [fontname=\"Helvetiva ,Arial , sans-serif\"]\n"
                    "edge [fontname=\"Helvetiva ,Arial , sans-serif\"]\n"
                    "rankdir=LR; \n"
                    "node [shape = doublecircle ] ; par ; \n"
                    "node [shape = circle] ; \n"
                    );

    InserirNode(&head, "Teste \n");
    while (fgets(linha, 100, entrada) != NULL)
    {
        contador++;
        if(contador == 1){
            // linha 1 - quantida de estados
            qntEstados = atoi(linha);
        }
        else if(contador <= qntEstados + 1){
            // linha 2 e 3 - estados
        }
        else if(contador == qntEstados + 2){
            // linha 4 - quantidade de simbolos
            qntAlfabeto = atoi(linha);
        }
        else if(contador <= qntEstados + qntAlfabeto + 2){
            // linha 5 e 6 - simbolos do alfabeto
        }
        else if(contador == qntEstados + qntAlfabeto + 3){
            // linha 7 - quantidade de transicoes
            qntTransicoes = atoi(linha);
        }
        else if(contador <= qntEstados + qntAlfabeto + qntTransicoes + 3){
            // linha 8, 9, 10 e 11 - transicoes
            //MudarHead(&head, strcat(head->data, linha));
            MudarHead(&head, linha);
        }
        else if(contador == qntEstados + qntAlfabeto + qntTransicoes + 4){
            // linha 12 - variavel inicial
        }
        else if(contador == qntEstados + qntAlfabeto + qntTransicoes + 5){
            // linha 13 - quantidade de estados finais
            qntEstadosFinais == atoi(linha);
        }
        else if(contador <= qntEstados + qntAlfabeto + qntTransicoes + qntEstadosFinais + 5){
                // linha 14 - estados finais
        }
        else{
            break;
        }
    }
    printList(head);
    freeList(head);
    fclose(entrada);
    fclose(saida);
}

int main(void){
    Visualizacao();

    return 0;
}
