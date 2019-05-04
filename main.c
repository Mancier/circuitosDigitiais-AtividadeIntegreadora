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

int main() {
    int value = 0, i = 0;
    printf("==> Entre com a sequencia de Q\n");
    printf("Para sair digite: 11\n\n");
    do{
        printf("%d => ", i+1);
        scanf("%d", &value);
        if(value == 11){
            printf("%d\n", i%2);
            if(!(i%2)) break; else printf("Insira mais um valor\n"); //Quebrando o laço inicial
        } else {
            i++;
            insert(value, 'q');
        }
    } while(value != 0 && value != 1);



    showList();
    return 0;
}