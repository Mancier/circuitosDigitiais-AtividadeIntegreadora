#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Nothing
#define ever ;; //Just for Fun
#define max 4

typedef struct truthTable{
    char *j;
    char *k;
    char *q;
    int valueDecimal;
    struct truthTable *next;
} TruthTable;

TruthTable *prim= NULL, *p, *q;

void insert(char *word, int value){
    int count = 0;
    p = malloc(sizeof(TruthTable));
    p->q = malloc(sizeof(char)*4);
    p->j = malloc(sizeof(char)*4);
    p->k = malloc(sizeof(char)*4);
    p->valueDecimal = value;

    !p ? exit(-1) : NULL;
    while (*word)
    {
        int aux = (int) *word;
        *(p->q+count) =  (aux-48) + '0';
        word++;
        count++;
    }
    p->next = NULL;
    if(prim != NULL) q->next = p; else prim = p; //Performance
    q = p;
}

//This function is called after the sorting
void equalsBits(TruthTable *pointer, int count){
    if(*(pointer->q+count) == '1'){
        *(pointer->j+count) = 'X';
        *(pointer->k+count) = '0';
    } else {
        *(pointer->j+count) = '0';
        *(pointer->k+count) = 'X';
    }
}
//This 2
void differentBits(TruthTable *pointer, int count){
    if(*(pointer->q+count) == '1'){
        *(pointer->j+count) = 'X';
        *(pointer->k+count) = '1';
    } else {
        *(pointer->j+count) = '1';
        *(pointer->k+count) = 'X';
    }
}

/*
 * Essa funcao executa uma "triagem" dos dados
 * Segundo a soma do qn e qn+1, vai ser redirecionado para funcoes
 * que irao determinar o j e k desses casos
 */

//Think a better way to resolve this point
void sorting(TruthTable *pointer){
    int count = max-1;
    p = pointer;
    q = prim;

    if(p->next != NULL){
        while (count >= 0){
            (*(p->q+count) == *(p->next->q+count)) ? equalsBits(pointer, count) : differentBits(pointer, count);
            count--;
        }
    } else {
        while (count >= 0){
            (*(p->q+count) == *(q->q+count)) ? equalsBits(pointer, count) : differentBits(pointer, count);
            count--;
        }
    }


}

//This too
void showTable(){
    TruthTable *pointer = NULL;
    int i = 0, count = 0;
    printf("\n\t\t======= Resultado =======\n");
    printf("\tI -> Q3 |Q2 |Q1 |Q0 ||J3 |K3 ||J2 |K2 ||J1 |K1 ||J0 |K0\n");
    for(pointer = prim; pointer->next != NULL; pointer = pointer->next){
        printf("\t%d -> ", pointer->valueDecimal);
        while(count < max){
            printf(" %c ", *(pointer->q+count));
            (count != max-1) ? printf("|") : NULL;
            count++;
        }
        count = 0;
        while(count < max){
            printf("|| %c | %c ", *(pointer->j+count), *(pointer->k+count)); count++;
        }
        count = 0;
        printf("\n");
    }
    printf("\t%d -> ", pointer->valueDecimal);
    while(count < max){
        printf(" %c ", *(pointer->q+count));
        (count != max-1) ? printf("|") : NULL;
        count++;
    }
    count = 0;
    while(count < max){
        printf("|| %c | %c ", *(pointer->j+count), *(pointer->k+count)); count++;
    }
    printf("\n");
}

//I dont know how, but i assure works so dont change nothing
char *convertionToBinary(int value){
    int c, d, count;
    char *pointer;
   
   count = 0;
   pointer = malloc(max);

   if (pointer == NULL)
      exit(EXIT_FAILURE);
     
   for (c = 3 ; c >= 0 ; c--)
   {
      d = value >> c;

      if (d & 1){
         *(pointer+count) = 1 + '0';
      }
      else {
         *(pointer+count) = 0 + '0';
      }
      count++;
   }
   *(pointer+count) = '\0';
   
   return pointer;
}

int main() {
    int value = 0;

    printf("==> Para mostrar o mapa, entre o valor correspondente a linha\n");
    printf("Para sair digite: 16\n");
    printf("Linha: ");
    do
    {
        scanf("%d", &value);
        while (p){
            if(p->valueDecimal == value){
                value = -1;
                break;
            }
            p = p->next;
        }
        if(value < 16 && value >= 0){

            insert(convertionToBinary(value), value);
            printf("Insira um novo valor: ");
        } else if(value == 16) {
            printf("Saindo...\n");
        } else {
            printf("Valor Inválido, digite novamente um valor entre 0 e 15\n");
            printf("Insira um novo valor: ");
        }
    } while (value != 16 || !(prim));

    for (p = prim; p->next != NULL; p = p->next) {
        sorting(p);
    }
    sorting(p);

    showTable();

    //free(q);
    free(p);
    free(prim);
    return 0;
}
