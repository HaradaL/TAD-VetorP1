#include <stdio.h>
#include "TAD-Vetor1.h"
//#include "TAD-Vetor2.h"

int main() {
    //int *vetor1;
    //vetor1 = {1,2,3};
    Vetor *v1;
    v1 = vetor_new();
    //int *v2 = {4, 2};
    //int *v3 = {7, 8};
    vetor_insert(v1, 1, 0);
    vetor_add(v1, 4);
    vetor_print(v1);
    // // vetor_insert(v1, 2, 1);
    // // vetor_insert(v1, 3, 2);
    // // vetor_insert(v1, 6, 0);
    // vetor_size(v1);
    //
    // vetor_remove1(v1, 2);
    //
    // vetor_print(v1);


    //vetor_free(v1);
}
