#ifndef PP1A_H_
#define PP1A_H_

typedef int *ksubset;

int bincoef(int n, int r);
ksubset initialization(int N);
void get_successor(ksubset set, int r, int n);  
int kSubsetLexRank(ksubset T, int k, int n);
int ranking(ksubset set, int r, int n);
void generate_subset(int n);
#endif

