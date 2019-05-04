#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ever ;; //Just for Fun

typedef struct truthTable{
    int j;
    int k;
    int q;
    struct truthTable *next;
} TruthTable;

TruthTable *prim= NULL, *p, *q;

void insert(int i, char option){
    p = malloc(sizeof(TruthTable));

    !p ? exit(-1) : NULL;

    switch (option){
        case 'j':
            p->j = i;
            break;
        case 'k':
            p->k = i;
            break;
        default:
            p->q = i;
            break;
    }

    p->next = NULL;

    if(prim != NULL) q->next = p; else prim = p;

    q = p;
}

void showList(){
    int i = 0;
    for(p = prim; p != NULL; p = p->next){
        printf("%d -> %d\n", i+1, p->q);
        i++;
    }
}

void equalsBits(TruthTable *pointer){
    if(pointer->q == 1){
        pointer->j = 2;
        pointer->k = 0;
    } else {
        pointer->j = 0;
        pointer->k = 2;
    }
}

void differentBits(TruthTable *pointer){
    if(pointer->q == 1){
        pointer->j = 2;
        pointer->k = 1;
    } else {
        pointer->j = 1;
        pointer->k = 2;
    }
}

/*
 * Essa funcao executa uma "triagem" dos dados
 * Segundo a soma do qn e qn+1, vai ser redirecionado para funcoes
 * que irao determinar o j e k desses casos
 */
void sorting(TruthTable *pointer){
    if(pointer->next){
        if((pointer->q + pointer->next->q) == 1){
            differentBits(pointer);
        } else {
            equalsBits(pointer);
        }
    } else {
        if((pointer->q + prim->q) == 1){
            differentBits(pointer);
        } else {
            equalsBits(pointer);
        }
    }
}

void showTable(TruthTable *pointer){
    int i = 0;
    printf("\n============ Resultado ============\n");
    printf("I | Qn | J | K\n");
    printf("--------------\n");
    for(p = prim; p->next != NULL; p = p->next){
        printf("%d| %d | %d | %d\n", i++, pointer->q, pointer->j, pointer->k);
        printf("--------------\n");
        i++;
    }
}

int main() {
    int value = 0, i = 0;

    /*
     * Coletando os valores de Qn
     */
    printf("==> Entre com a sequencia de Q\n");
    printf("Para sair digite: 11\n\n");
    for(ever) {
        if(value == 11) break;
        do {
            printf("%d => ", i + 1);
            scanf("%d", &value);
            if (value == 11) {
                if (!(i % 2))
                    break; else printf("Insira mais um valor e depois digite 11 para sair\n"); //Quebrando o laço inicial
            } else {
                i++;
                insert(value, 'q');
            }
        } while (value != 0 && value != 1);
    }
    // ======= Fim =======

    showList();

    /*
     * Tratamento dessas informações de modo interessante
     */
    for (p = prim; p->next != NULL; p = p->next) {
        sorting(p);
    }
    showTable(prim);
    return 0;
}