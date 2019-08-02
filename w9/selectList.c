#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "IntList.h"

int main(int argc, char **argv)
{
    IntList L = newIntList();
    // read in a list of numbers and append into a list
    for (int i = 1; i < argc; i++) 
        IntListInsert(L, atoi(argv[i]));
    showIntList(L);
    IntList sortedL = IntListSort(L);
    assert(IntListIsSorted(sortedL));
    printf("Yeetyasortedya\n");
    showIntList(sortedL);
}