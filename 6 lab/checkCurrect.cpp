#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
 
typedef struct vertex
{
    long long val = 0;
    int left = 0;
    int right = 0;
    int parent = 0;
} vertex;
 
bool check_vert(vertex * arr, int check, long long min, long long max)
{
    if (arr[check].val <= min)
        return false;
 
    if (arr[check].val >= max)
        return false;
 
    if (arr[check].left > 0)
        if (!check_vert(arr, arr[check].left, min, arr[check].val))
            return false;
 
    if (arr[check].right > 0)
        if (!check_vert(arr, arr[check].right, arr[check].val, max))
            return false;
    return true;
}
 
bool check_tree(vertex * arr)
{
    if (arr[0].left > 0)
        if (!check_vert(arr, arr[0].left, LLONG_MIN, arr[0].val))
            return false;
    if (arr[0].right > 0)
        if (!check_vert(arr, arr[0].right, arr[0].val, LLONG_MAX))
            return false;
    return true;
}
 
 
int main()
{
    FILE * in = fopen("check.in", "r");
    FILE *  out = fopen("check.out", "w");
 
    int size;
    fscanf(in, "%d", &size);
    if (size < 2) {
        fprintf(out, "YES");
        return 0;
    }
 
    vertex * arr = new vertex[size];
    int parent, check, position;
    int left, right;
    long long val;
    fscanf(in, "%lld %d %d", &val, &left, &right);
    arr[0].val = val;
    arr[0].left = left - 1;
    arr[0].right = right - 1;
    long long lower = val;
    long long higher = val;
    for (int pos = 1; pos < size; pos++) {
        fscanf(in, "%lld %d %d", &val, &left, &right);
        left--; right--;
        arr[pos].val = val;
        arr[pos].left = left;
        arr[pos].right = right;
 
        if (left > -1)
            arr[left].parent = pos;
        if (right > -1)
            arr[right].parent = pos;
    }
 
    if (!check_tree(arr))
        fprintf(out, "NO");
    else fprintf(out, "YES");
 
    return 0;
}