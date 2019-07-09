#include <stdio.h>
#include <stdlib.h>



void print(int n){
    if(n <= 0){
    return; 
    }
    printf("Hello!\n");
    print(n-1);
   
}




int main(){
    print(5);
    return 0;
}
