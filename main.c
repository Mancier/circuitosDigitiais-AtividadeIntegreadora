#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ever ;; //Just for Fun

/*
*   ==>> Remember <<===
*    char *point => Return the value
*    char &pont => Return the memory address
*    char point => Return all data on that
*/

typedef struct truthTable{
    char *j;
    char *k;
    char *q;
    int count;
    struct truthTable *next;
} TruthTable;

TruthTable *prim= NULL, *p, *q;

void insert(char *word){
    p = malloc(sizeof(TruthTable));
    !p ? exit(-1) : NULL;
    p->q = word;
    p->next = NULL;
    if(prim != NULL) q->next = p; else prim = p; //Performance
    q = p;
}

//This function is called after the sorting
void equalsBits(TruthTable *pointer){
    if(pointer->q == 1){
        pointer->j = 'X';
        pointer->k = '0';
    } else {
        pointer->j = '0';
        pointer->k = 'X';
    }
}
//This 2
void differentBits(TruthTable *pointer){
    if(pointer->q == 1){
        pointer->j = 'X';
        pointer->k = '1';
    } else {
        pointer->j = '1';
        pointer->k = 'X';
    }
}

/*
 * Essa funcao executa uma "triagem" dos dados
 * Segundo a soma do qn e qn+1, vai ser redirecionado para funcoes
 * que irao determinar o j e k desses casos
 */

//Think a better way to resolve this point
void sorting(TruthTable *pointer){
    if (pointer->next) {
        if ((pointer->q + pointer->next->q) == 1) {
            differentBits(pointer);
        } else {
            equalsBits(pointer);
        }
    } else {
        if ((pointer->q + prim->q) == 1) {
            differentBits(pointer);
        } else {
            equalsBits(pointer);
        }
    }
}

//This too
void showTable(TruthTable *pointer){
    int i = 0;
    printf("\n======= Resultado =======\n");
    printf("\tI -> Q || J | K\n");
//    printf("--------------\n");
    for(pointer = prim; pointer->next != NULL; pointer = pointer->next){
        printf("\t%d -> %d || %c | %c\n", i+1, pointer->q, pointer->j, pointer->k);
//        printf("--------------\n");
        i++;
    }
    printf("\t%d -> %d || %c | %c\n", i+1, pointer->q, pointer->j, pointer->k);
}

int main() {
    int i = 0;
    char *value = malloc(sizeof(char)*4);

    /*
     * Coletando os valores de Qn
     */
    printf("==> Entre com a sequencia de Q\n");
    printf("Para sair digite: 1111\n\n");
    for(ever) {
        if(value == 1111) break;
        do {
            printf("%d => ", i + 1);
            scanf("%d", &value);
            if (value == 1111){
                if(i % 2) {
                    printf("Insira mais um valor e depois digite 11 para sair\n");
                } else {
                    break;
                }
            }
            if(value != 0 && value != 1){
                printf("->> Valor Invalido!\nInsira um novo valor\n");
            }
            else {
                i++;
                insert(value);
            }
        } while (value != 0 && value != 1);
    }
    // ======= Fim =======

    /*
     * Tratamento dessas informações de modo interessante
     */
    for (p = prim; p->next != NULL; p = p->next) {
        sorting(p);
    }
    sorting(p);

    showTable(prim);
    return 0;
}