#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n = 8;
int power(int base, int exp);
int* calculate_linear_function( int n, int omega);
int main(){
    int f[8] ={0,0,1,1,1,0,1,0};
    int* ptr_f = f;
    int* S = (int*)malloc(n * sizeof(int));
    int* omega_bit = (int*)malloc(n * sizeof(int));
    int* x_bit = (int*)malloc(n * sizeof(int));
    int exponent;
    int result;
    int* L_omega = (int*)malloc( n * sizeof(int));

    for(int omega = 0; omega < n; omega++){
        int sum = 0;
        //printf("omega = %d\n", omega);
        L_omega = calculate_linear_function(n, omega);
        for(int x = 0; x < n; x++){
            //printf("L_omega[%d] = %d\n", x, L_omega[x]);
            result = power(-1, L_omega[x]);
           // printf("-1^%d = %d\n", L_omega[x], result);
            sum = (f[x] * result) + sum;
        }
        S[omega] = sum;
        printf("S[%d] = %d\n", omega, S[omega]);
        //printf("\n");
    }

    free(S);
    S = NULL;
    return 0;
}

int* calculate_linear_function(int n, int omega){
    int result;
    int* omega_bit = (int*)malloc(n * sizeof(int));
    int* x_bit = (int*)malloc(n * sizeof(int));
    int* L_omega = (int*)malloc(n * sizeof(int));
    for(int x = 0; x < n; x++){
        int temp = 0;
        for(int index = 0; index < n; index++) {
            omega_bit[index] = (omega >> index) & 0x01;
            x_bit[index] = (x >> index) & 0x01;
            //printf("omega_bit[%d] = %d\n", index, omega_bit[index]);
            //printf("x_bit[%d] = %d\n", index, x_bit[index]);
            temp = (omega_bit[index] * x_bit[index]) ^ temp;
            //printf("\n");
        }
        L_omega[x] = temp;
        //printf("L_omega[%d] = %d\n", x, L_omega[x]);
        //printf("\n");
        //result = power(-1, L_omega[x]);
        //printf("-1^%d = %d\n", L_omega[x], result);
        //sum = (f[x] * result) + sum;
    }
    return L_omega;
}

int power(int base, int exp){
    int result = 1;
    while (exp != 0) {
        result *= base;
        --exp;
    }
    return result;
}