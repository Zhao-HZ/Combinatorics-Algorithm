#include "../include/pp1a.h"
#include <stdlib.h>

int size;

int bincoef(int n, int r) {
    int i, b;
    if ((r < 0) || (n < r))
        return (0);
    if ((2 * r) > n)
        r = n - r;
    b = 1;
    if (r > 0)
        for (i = 0; i <= (r - 1); i = i + 1)
            b = (b * (n - i)) / (i + 1);
    return b;
}
 
ksubset initialization(int N) {
    ksubset subset = (ksubset) calloc(N, 4);
    return subset; 
}

void get_successor(ksubset set, int r, int n) {
    int j = r - 1;

    // Special case: if subset is empty.
    if (r == 0) {
        size = 0;
        for (int i = 0; i < n; i++) {
            set[i] = i + 1;
        }
    } 

    while (j != -1) {
        if (set[j] != n) {
            break;
        }
        j--;
        n--;
    }

    if (j == -1) {
        size = --r;
        for (int i = 0; i < size; i++) {
            set[i] = i + 1;
        } 
    } else {
        // j++;
        j = r - 1;
        size = r;
        if ((set[j] + 1) > n) {
            j--;
            while (j >= 0) {
                if (set[j] == set[j + 1] - 1) {
                    j--;
                } else {
                    set[j]++;
                    for (int i = j + 1; i <= r - 1; i++) {
                        set[i] = set[i - 1] + 1;
                    }
                    break;
                }
            }
        } else {
            set[j]++;
        }
    }
}

int kSubsetLexRank(ksubset arr, int k, int n) {
    ksubset T = (ksubset) malloc((k + 1) * sizeof(int));
    for (int i = 0; i < k; i++) {
        T[i + 1] = arr[i];
    }
    int i, lo, hi;
    int result = 0;
    T[0] = 0;
    for (i = 1; i <= k; i = i + 1)
    {
        lo = T[i - 1] + 1;
    
        hi = T[i] - 1;
        if (lo <= hi)
        {
            for (int j = lo; j <= hi; j = j + 1)
                result = result + bincoef(n - j, k - i);
        }
    }
    free(T);
    return result;
}

int ranking(ksubset set, int r, int n) {
    int result = 0;
    if (r == n) {
        return 0;
    } else if (!r) {
        return (1 << n) - 1;
    } else if (r == n - 1) {
        result += kSubsetLexRank(set, r, n);
        result++;
        return result;
    } else {
        int d = n - r - 1;
        for (int i = 1; i <= d; i++) {
            result += bincoef(n, i + r);
        }
        result++;
        result += kSubsetLexRank(set, r, n);
        return result;
    }
}
