
#ifndef PP1C_N_
#define PP1C_N_
typedef int *set;
// int len_marklist;
void get_successor_permutation(set s, int n);
int rank_permutation(set s, int n);
set unrank_permutation(int r, int n);
int *get_marklist(set s, int n);
void list_to_set(set s, int *marklist, int len, int n);
void free_all(int *arr);
#endif