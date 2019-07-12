#include <stdio.h>
#include <stdlib.h>


void printNumberRev(unsigned n){
    if(n==0){
        return;
    }
    /tail recursion , no stack needed
    printf("%u\n",n);
    printNumberRev(n-1);

}

void printNumberFord(unsigned n){
    if(n==0){
        return;
    }
    printNumberFord(n-1);
    printf("%u\n",n);
}

long factorial (unsigned n){
    if(n == 0){
        return 1L;
    }
}



int main()
{    
    printNumberRev(10);
    printf("Hello World\n");
    printNumberFord(10);
    printf("Hello World");

    return 0;
}
