#include "vector.h"
#include "vector.c"
#include <stdio.h>

//Casts variables to char * and returns the result of strcmp with those variables.
int cmpstr(const void* a, const void* b){
    const char *aa = a;
    const char *bb = b;
    return strcmp(aa,bb);
}

//helper function: prints each element of our Vector *v.
void printVector(Vector *v){
    int i;
    char *value;
    for (i=0; i < v->usedSpace; i++){
        value = v->parray + (i * CELLSIZE);
        printf("%s", value);
    }
}

int main(int argc, char *argv[]){
    Vector v;
    Vector *p = &v;
    Vector_ctor(p);

    FILE *fp; 
    char buffer [CELLSIZE];
    char *b = buffer;
    fp = fopen( argv[1],"r");
      
    while (fgets(buffer, CELLSIZE, fp) != NULL){
        Vector_push_back(p, b);
    }

    fclose(fp);
    
    qsort(p->parray, p->usedSpace, CELLSIZE, cmpstr);
    printVector(p);

    return 0;
}


