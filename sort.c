#include "vector.h"
#include "vector.c"
#include <stdio.h>

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
        printf("%p - %s\n", value, value);
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
    
    printVector(p);
    qsort(p->parray, p->usedSpace, CELLSIZE, cmpstr);
    printVector(p);

    return 0;
}


