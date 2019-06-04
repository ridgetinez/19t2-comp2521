/*
 * Extremely spartan linked list library
 * Accentuate definition and benefits of an ADT
 * 
 * ~arm
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct _list {
    int val;
    struct _list *next;
};

static int LinkedListSumRecurse(LinkedList l);
static int LinkedListSumIter(LinkedList l);

LinkedList LinkedListInit()
{
    /* TODO */
    return NULL;
}

void LinkedListAppend(LinkedList l, int v)
{
    /* TODO */
    return;
}

int LinkedListSum(LinkedList l)
{
    /* TODO */
    return LinkedListSumIter(l) + LinkedListSumRecurse(l);
}

static int LinkedListSumRecurse(LinkedList l)
{
    /* TODO */
    return 0;
}

static int LinkedListSumIter(LinkedList l)
{
    /* TODO */
    return 0;
}