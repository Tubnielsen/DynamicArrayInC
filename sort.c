#include "vector.h"
#include "vector.c"
#include <stdio.h>

/*int cmpstr(const void* a, const void* b){
    const char* aa = *(const char**)a;
    const char* bb = *(const char**)b;
    return strcmp(aa,bb);
}*/

//helper function: prints each element of our Vector *v.
void printVector(Vector *v){
    int i;
    for (i=0; i < v->usedSpace; i++){
	// HVORDAN LÆSER VI VÆRDIEN I HUKOMELSEN?
        char *print = v->parray + (i * CELLSIZE);
        printf("%p - %s\n", print);
    }
}

int main(int argc, char *argv[]){
    Vector v;
    Vector *p = &v;
    Vector_ctor(p);
    char mystring[] = "ayy";
    char *lmao = mystring;
    Vector_push_back(p, lmao);
    Vector_push_back(p, "hello");
    Vector_push_back(p, "hasdf");
    FILE *fp; 
    char buffer [CELLSIZE];
    char *b = buffer;
    fp = fopen( argv[1],"r");
      
    while (fgets(buffer, CELLSIZE, fp) != NULL){
        //Vector_push_back(p, b);
        //printf("%s", b);
        //puts(buffer);
    }

    fclose(fp);
    
    printVector(p);
    //qsort(p->parray, p->usedSpace, CELLSIZE, cmpstr);
    //printVector(p);

    return 0;
}


