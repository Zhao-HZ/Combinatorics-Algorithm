#include <stdio.h>
#include <stdlib.h>
#include "./include/pp1c.h"
#include "./include/pp1a.h"

extern int size;
void print_arr(int *a, int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int N = 7;
    int r = 5;
    set s = unrank_permutation(r, N);    
    print_arr(s, N);
    free(s);
    return 0;
}
