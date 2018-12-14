#include "vector.h"
#include "vector.c"
#include <stdio.h>

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
        printf("%s", b);
        //puts(buffer);
    }

    fclose(fp);
    return 0;
}

void sortVector(Vector *v){
    qsort(v->parray, v->usedSpace,CELLSIZE)

}