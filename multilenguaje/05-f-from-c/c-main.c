//gcc c-main.c f-sum.o -o c-main.e
#include <stdio.h>
//#include "c-sum.h" Ahora llamo a la subrutina de fortran.

#define NUM 200

extern void sum_abs_(int *inp, int* num, int* asum);

int main(int argc, char **argv)
{
    int data[NUM], num, i, sum;

    num = NUM;
    for (i=0; i < num; i++) {
        data[i] = i - 100 + 1;  /* NOTE: difference in array numbering */  
    }

    sum_abs_(data, &num, &sum);
    printf("sum=%d\n", sum);
    return 0;
}
