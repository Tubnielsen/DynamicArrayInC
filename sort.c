#include "vector.h"
#include "vector.c"
#include <stdio.h>

int cmpstr(const void* a, const void* b){
    const char* aa = *(const char**)a;
    const char* bb = *(const char**)b;
    return strcmp(aa,bb);
}

void printVector(Vector *v){
    for (int i=0; i < v->usedSpace; i++){
        void *print = v->parray + i * CELLSIZE;
        printf("%x \n", &print);
    }
}

int main(int argc, char *argv[]){
    Vector v;
    Vector *p = &v;
    Vector_ctor(p);
    FILE *fp; 
    char buffer [CELLSIZE];
    char *b = &buffer;
    fp = fopen( argv[1],"r");
    
    
    while (fgets(buffer, CELLSIZE, fp) != NULL){
        Vector_push_back(p, b);
        //printf("%s", b);
        //puts(buffer);
    }

    fclose(fp);
    printVector(&p);
    //qsort(p->parray, p->usedSpace, CELLSIZE, cmpstr);
    //printVector(p);

    return 0;
}


