#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ever ;; //Just for Fun
#define max 4;

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
    int count = 0;
    //Alocando tudo
    p = malloc(sizeof(TruthTable));
    p->q = malloc(sizeof(char)*5);
    p->j = malloc(sizeof(char)*5);
    p->k = malloc(sizeof(char)*5);

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
    if(*(pointer->q) == '1'){
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
    int count = 0;
    while (*(pointer->q)){ //Remember => \0 is false
        if(*(pointer->q) == *(pointer->next->q++)){
            equalsBits(pointer, count);
        } else {
            differentBits(pointer, count);
        }
        pointer->q++;
        count++;
    }
}

//This too
void showTable(TruthTable *pointer){
    int i = 0;
    printf("\n======= Resultado =======\n");
    printf("\tI -> Q || J | K\n");
//    printf("--------------\n");
    for(pointer = prim; pointer->next != NULL; pointer = pointer->next){
        printf("\t%d -> %s || %s | %s\n", i+1, pointer->q, pointer->j, pointer->k);
//        printf("--------------\n");
        i++;
    }
    printf("\t%d -> %s || %s | %s\n", i+1, pointer->q, pointer->j, pointer->k);
}

//I dont know how, but i assure works so dont change nothing
char *convertionToBinary(int value){
    int c, d, count;
    char *pointer;
   
   count = 0;
   pointer = malloc(4);

   if (pointer == NULL)
      exit(EXIT_FAILURE);
     
   for (c = 4 ; c >= 0 ; c--)
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
   
   return  pointer;
}

int main() {
    int value = 0;
    /*
     * Coletando os valores de Qn
     */
    printf("==> Para mostrar o mapa, entre o valor correspondente a linha\n");
    printf("Para sair digite: 16\n");
    printf("Linha: ");
    do
    {
        scanf("%d", &value);
        if(value < 16 && value > 0){
            insert(convertionToBinary(value));
            printf("Insira um novo valor: ");
        } else {
            printf("Valor Inválido, digite novamente um valor entre 0 e 15\n");
            printf("Insira um novo valor: ");
        }
    } while (value != 16 || !(prim));

    for (p = prim; p->next != NULL; p = p->next) {
        sorting(p);
    }
    sorting(p);

    showTable(prim);

    free(p);
    free(prim);
    free(q);
    return 0;
}