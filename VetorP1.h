#include <stdio.h>
#include <stdlib.h>
#define LENGTH 5
//#include "TAD-Vetor2.h"

typedef struct{
int *vetor;
int size;       //qtde de elementos
int length;     //tamanho real de vetor
} Vetor;

typedef int DataType;
typedef enum {FALSE, TRUE} Boolean;

Vetor *vetor_new();
void vetor_free(Vetor* v);
void vetor_print(Vetor* m);
Boolean vetor_insert(Vetor* v, DataType element, int index);
Boolean vetor_add(Vetor* v, DataType element);
DataType vetor_remove1(Vetor* v, int index);
//Boolean vetor_remove2(Vetor* v, int index, Datatype* ptr);
DataType vetor_shift1(Vetor* v);
//Boolean vetor_shift2(Vetor* v, Datatype* ptr);
DataType vetor_get1(Vetor* v, int index);
Boolean vetor_get2(Vetor* v, int index, DataType *ptr);
//Datatype* vetor_get3(Vetor* v, int index);
Boolean vetor_set(Vetor* v, int index, DataType valor); //alterar uma célula do vetor
void vetor_map(Vetor* v, void (*funcao)(DataType*));
Vetor* vetor_sub1(Vetor* v, int index);
Vetor* vetor_sub2(Vetor* v, int start, int end);

//Recebe o vetor, aloca o tamanho de numero de elementos na memória
Vetor *vetor_new() {
  int i;
  Vetor *vet = (Vetor *)malloc(sizeof(Vetor));
  vet->size = 0;
  for (i = 0; i < LENGTH; i++){
    vet->vetor[i] = 0;
  }
  return vet;
}

void vetor_free(Vetor* v) {
  free(v);
}

void vetor_print(Vetor *m) {
    int i, aux = 0;
    for (i = 0; i < LENGTH; i++) {
        printf("%d, ", m->vetor[i]);
    }
}

void vetor_resize(Vetor *v) {
    int i, j, *novoVetor;
    if (v-> size == LENGTH)
        novoVetor = (int *)realloc(v->vetor, v-> length * 2 * sizeof(int));
        //v-> vetor = (int *)realloc(v->vetor, v-> length * 2 * sizeof(int));
    for (i = 0; i < v-> size; i++) {
        *(novoVetor + i) = v->vetor[i];
    }
    free(v-> vetor);
}

/*
A funcionalidade de inserção deve providenciar espaço sempre que necessário. Crie uma função
auxiliar para isso e utilize a estratégia de dobrar o tamanho do vetor sempre que houver
necessidade de espaço.
*/

Boolean vetor_insert(Vetor *v, DataType element, int index) {
    int i;
    if (v-> size == LENGTH)
        vetor_resize(v);
        return FALSE;
    for (i = 0; i <= index; i++) {
      // vet[i] = malloc(int);
        if (i == index)
            v->vetor[i] = element;
    }
    v->size++;
    return TRUE;
}

Boolean vetor_add(Vetor* v, DataType element) {
    if (v-> size == LENGTH) {
        vetor_resize(v);
        return FALSE;
    }
    v-> vetor[v->size++] = element;
    //v->size++;
    return TRUE;
}

/*
A remoção deve se preocupar com a quantidade de espaço ocioso no vetor. Caso a remoção
resulte em uma taxa de ocupação abaixo de 25%, o tamanho do vetor deve ser reduzido pela
metade. Crie uma função auxiliar para verificar e efeturar a redução.
*/

DataType vetor_reduz(Vetor *v) {
    int *vet ;
    vet = (int *)realloc(v-> vetor, (LENGTH / 2) * sizeof(int));
    int i, j;
    for (i = 0; i < v->size; i++) {
      for (j = 0; j < v->size; j++) {
        vet[i] = v->vetor[j];
      }
    }
    return (int)vet;
}

DataType vetor_remove1(Vetor *v, int index) {
    if (LENGTH % 1/4 >= 0.25)
        vetor_reduz(v);
    int i;
    for (i = 0; i <= index; i++) {
        if (i == index)
            v->vetor[i] = 0;
    }
    v->size--;
    return (int)v;
}

Boolean vetor_remove2(Vetor *v, int index, DataType *ptr) {
    if (LENGTH % 1/4 >= 0.25) {
        vetor_reduz(v);
        return FALSE;
    }
    int i;
    for (i = 0; i <= index; i++) {
        if (i == index)
            v->vetor[i] = (DataType)0;
    }
    v->size--;
    return TRUE;
}
/*
Acessar um elemento do vetor
Essa funcionalidade deve ser disponibilizada por meio de três funções. As funções provêm o
mesmo comportamento, porém, de formas distintas.
*/

DataType vetor_get1(Vetor* v, int index) {
    int i;
    for (i = 0; i < index; i++) {
        if (i == index) return v->vetor[i];
    }
    return (int)v->vetor[i];
}

// Boolean vetor_get2(Vetor* v, int index, DataType *ptr) {
//     int i;
//     for (i = 0; i < index; i++) {

//     }
// }


// Boolean vetor_get2(Vetor* v, int index, DataType *ptr);

//Alterar um elemento no vetor

Boolean vetor_set(Vetor* v, int index, DataType valor) {
    int i;
    for (i = 0; i <= index; i++) {
        if (i == index) v->vetor[i] = valor;
    }
    return TRUE;
}

/*
Aplicar uma alteração à todos os elementos do vetor.
Essa funcionalidade pode ser obtida por meio de uma função que recebe por parâmetro um
ponteiro da função que realizará a alteração em cada elemento. Essa funcionalidade já foi discutida
em sala de aula.
A função recebe o vetor e o ponteiro da função que será invocada para cada elemento.
*/
// void vetor_map(Vetor* v, void (*funcao)(DataType*)) {
//     int size = v->size;
//     int i;
//     for (i = 0; i < size; i++) {
//         funcao();
//     }
// }

/*
O sub‒vetor pode ser adquirido com base nos índices do vetor.
A primeira função recebe o vetor v e o índice index e cria o sub‒vetor a partir de index. Quando o
índice é negativo, ele representará as posições do fim para o inicio. Por exemplo, o índice ́‒1́
representa a última posição do vetor, ‒2 a penúltima e assim por diante.
A segunda função recebe o intervalo desejado para a criação do sub‒vetor.
*/

Vetor* vetor_sub1(Vetor* v, int index);
Vetor* vetor_sub2(Vetor* v, int start, int end);

//Acessar o tamanho do vetor

int vetor_size(Vetor* v) {
    int size = v-> size;
    return size;
}
