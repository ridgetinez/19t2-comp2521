#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key, val;
} Item;

static int isStableSort(Item[],Item[], int, int);

int main(void)
{                           
    Item orig[4] = {{2,1}, {1,2}, {1,3}, {1,4}};
    Item sorted[4] = {{1,3}, {1,2}, {1,4}, {2,1}};
    for (int i = 0; i < 4; i++) {
        printf("Orig: (%d,%d), Sorted: (%d,%d)\n", orig[i].key, orig[i].val, sorted[i].key, sorted[i].val);
    }
    printf("IsStableSort?: %d\n", isStableSort(orig, sorted, 0, 4));
}

// O(N^2) ~> O(NlogN) ~> O(N)
static int
isStableSort(Item original[], Item sorted[], int lo, int hi)
{
    // int *marked = malloc(sizeof(int) * (hi-lo));
    for (int i = lo; i < hi; i++) {
        int current_key = original[i].key;
        int j = 0, k = 0;
        while (j < hi && k < hi) {
            // find the first position in original where key == current_key
            for (; j < hi; j++)  if (original[j].key == current_key) break;
            // find the first position in sorted where key == current_key
            for (; k < hi; k++)  if (sorted[k].key == current_key) break;
            if (original[j].val != original[k].val) return 0;
            j++, k++;
        }
    }
    return 1;
}









/*
static int
isStableSort(Item original[], Item sorted[], int lo, int hi)
{
    // mark - sweep algorithm O(n^2)
    // (1) we're on a given element of original
    // (2) We want to find an element in sorted that has the same key as original
    // (3) If these two don't have the same value -> return 0
    // (4) Continue for the rest of the keys
    int *marked_orig = calloc(0, sizeof(int) & (hi - lo));
    int i_orig, i_sorted;
    for (int i = lo; i < hi; i++) {
        if (marked_orig[i-lo]) continue;
        int curr_key = original[i].key;
        i_orig = i; i_sorted = 0;
        while (i_orig < hi && i_sorted < hi) {
            // Find the next element with the same key in original
            for (; i_orig < hi; i_orig++) {
                if (original[i_orig].key == curr_key) break;
            }
            // Find the next element with the same key in sorted
            for (; i_sorted < hi; i_sorted++) {
                if (sorted[i_sorted].key == curr_key) break;
            }
            // compare if the two of them have the same value otherwise -> return 0; 
            if (i_orig < hi && i_sorted < hi && sorted[i_sorted].val != original[i_orig].val) return 0;
            marked_orig[i_orig] = 1;
            // go to next
            i_sorted++; i_orig++;
        }
    }
    return 1;
}
*/