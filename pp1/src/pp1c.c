#include "../include/pp1c.h"
#include "stdlib.h"

int len_marklist;

// A list to mark which element have been swap.
// The index of the marklist is the position of number in set
int *get_marklist(set s, int n) {
    int len = n / 2;
    int *list = (int *) calloc(n, 4);
    for (int i = 0; i < len; i++) {
        if (s[i] != i + 1) {
            list[i] = 1;
        }
    }    
    len_marklist = len; 
    return list;
}

void list_to_set(set s, int *marklist, int len, int n) {
    for (int i = 0; i < len; i++) {
        if (marklist[i] == 0) {
            s[i] = i + 1;
        } else {
            s[i] = n - i;
        }
    }
    if (n & 1) { // If n is odd
        s[len] = len + 1;
        len++;
        for (int i = len; i < n; i++) {
            if (marklist[n - i - 1] == 0) {
                s[i] = i + 1;
            } else {
                s[i] = n + 1 - s[n - i - 1];
            }
        }
    } else { // If n is even
        for (int j = len; j < n; j++) {
            if (marklist[n - j + 1] == 0) {
                s[j] = j + 1;
            } else { // It has been swap
                s[j] = n + 1 - s[n - j + 1];
            } 
        } 
    }
}

void free_all(int *arr) {
    free(arr);
}

void get_successor_permutation(set s, int n) {
    int *list = get_marklist(s, n);
    if (list[len_marklist - 1] == 0) {
        list[len_marklist - 1] = 1;
    } else {
        int carry = 1;
        list[len_marklist - 1] = 0;
        for (int i = len_marklist - 2; i >= 0; i--) {
            if (carry == 1 && list[i] == 1) {
                list[i] = 0;
            } else if (carry == 1 && list[i] == 0) {
                list[i] = 1;
                carry = 0;
            } 
        }
    }
    list_to_set(s, list, len_marklist, n);        
    free(list); 
}

int rank_permutation(set s, int n) {
    int *list = get_marklist(s, n);
    int result = 0;
    for (int i = 0; i < len_marklist; i++) {
       result += list[len_marklist - 1 - i] * (1 << i); 
    }
    free(list);
    return result;
}

set unrank_permutation(int r, int n) {
    // n is the cardinality of one set.
    int len = n / 2;
    int *list = (int *) calloc(len, 4);
    int remainder;
    int flag = len - 1; 
    set s = (set) malloc(4 * n);
    // Remember to free it!
    while (r != 0) {
        remainder = r % 2;
        r = r / 2;
        if (remainder == 1) {
            list[flag] = 1;
        } else {
            list[flag] = 0;
        }
        flag--;
    } 
    list_to_set(s, list, len, n);
    // free(list);
    return s;
}