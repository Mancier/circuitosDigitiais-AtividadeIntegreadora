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
    if(pointer->q == '1'){
        pointer->j = 'X';
        pointer->k = '0';
    } else {
        pointer->j = '0';
        pointer->k = 'X';
    }
}
//This 2
void differentBits(TruthTable *pointer){
    if(pointer->q == '1'){
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
void sorting(TruthTable *parallel){
     //Runnig in the string
    while (*(parallel->q)){ //Remember => \0 is false
        if(*(parallel->q) == *(parallel->next->q++)){
            equalsBits(parallel);
        } else {
            differentBits(parallel);
        }
        *parallel->q++;   
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

//I dont know how, but i assure works so dont change nothing
char *convertToBinary(int value){
    int c, d, count;
    char *pointer;
   
   count = 0;
   pointer = (char*)malloc(3);

   if (pointer == NULL)
      exit(EXIT_FAILURE);
     
   for (c = 4 ; c >= 0 ; c--)
   {
      d = value >> c;

      printf("Convertion: %d \n", d);
     
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
    char *wordBinary = malloc(sizeof(char)*4);

    /*
     * Coletando os valores de Qn
     */
    printf("==> Para mostrar o mapa, entre o valor correspondente a linha\n");
    printf("Para sair digite: 16\n");
    printf("Linha: ");
    do
    {
        scanf("%d", &value);
        if(!(value > 16 || value < 0)){
            insert(convertionToBinary(value));
            printf("Insira um novo valor: ");
        } else {
            printf("Valor Inválido, digite novamente um valor entre 0 e 15\n");
            printf("Insira um novo valor: ");
        }
    } while (value != 16);

    for (p = prim; p->next != NULL; p = p->next) {
        sorting(p);
    }
    sorting(p);

    showTable(prim);
    return 0;
}