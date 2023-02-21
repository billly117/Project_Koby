#include <assert.h>
#include <stdio.h>

int max2(int a, int b){
    if(a > b) return a;
    else return b;
}

int max3(int a, int b, int c){
    if(max2(a,b)>c) return max2(a,b);
    else return c;
}

void ligne(int rep){
    for(int i=0; i<rep; i++){
        printf("*");
    }
}
void colonne(int rep){
    for (int i = 0; i < rep; i++){
        printf("*\n");
    }    
}

void triangle(int l){
    for(int i=0; i<l; i++){
        for(int j=0; j<i+1;j++){
            printf("*");
        }
        printf("\n");
    }
}

void alternance(int a, int b, int rep){
    for(int i=0; i<rep/2; i++){ // On suposse que le 3eme argument est toujours pair
        ligne(a);
        printf("\n");
        ligne(b);
        printf("\n");
    }
}

void croix_negative(int rep){
    if (rep%2 == 0) rep+=1;


}
int main(void){
    // Tests max2
    printf("Les tests de max2 sont des asserts\n\n");
    assert(max2(1,2) == 2);
    assert(max2(2,1) == 2);
    assert(max2(1,1) == 1);
    assert(max2(-1,-2) == -1);
    assert(max2(-2,-1) == -1);
    assert(max2(-1,-1) == -1);
    assert(max2(-1,2) == 2);
    assert(max2(2,-1) == 2);

    // Tests max3
    printf("Les tests de max3 sont des asserts\n\n");
    assert(max3(-1,-1,-1) == -1);
    assert(max3(1,2,3) == 3);
    assert(max3(-1,-2,-3) == -1);
    assert(max3(-2,7,-5) == 7);

    ligne(15);
    printf("\n\n");
    colonne(15);
    printf("\n");
    triangle(5);
    printf("\n\n");
    alternance(5,3,8);
    return 0;
}