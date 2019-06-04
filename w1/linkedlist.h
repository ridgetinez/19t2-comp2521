#ifndef _LINKEDLIST
#define _LINKEDLIST

typedef struct _list *LinkedList;

LinkedList LinkedListInit();
void LinkedListAppend(LinkedList, int);
int LinkedListSum(LinkedList);

#endif