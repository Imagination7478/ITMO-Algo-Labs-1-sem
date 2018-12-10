#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
 
typedef struct Tree {
    long long k = 0;
    int l = 0;
    int r = 0;
    int before = 0;
};
 
int main() {
    FILE * in = fopen("height.in", "r");
    FILE * out = fopen("height.out", "w");
    int size;
    fscanf(in, "%d", &size);
    if (size < 3) 
    {
        fprintf(out, "%d", size);
        return 0;
    }
 
    Tree * arr = new Tree[size];
 
    int maxbefore = 0;
    int l, r;
    long long k;
 
    for (int i = 0; i < size; i++) 
    {
        fscanf(in, "%lld %d %d", &k, &l, &r);
        l--; r--;
        arr[i].k = k;
        arr[i].l = l;
        arr[i].r = r;
        if (arr[i].before > maxbefore)
            maxbefore = arr[i].before;
 
        if (l > -1)
            arr[l].before = arr[i].before + 1;
 
        if (r > -1)
            arr[r].before = arr[i].before + 1;
    }
 
    fprintf(out, "%d", maxbefore + 1);
    delete[] arr;
    return 0;
}