#include <stdio.h>
#include <stdlib.h>

#define head(L) ((L)->val)
#define tail(L) ((L)->next)
#define empty(L) ((L) == NULL)

typedef struct _list {
    int val;
    struct _list *next;
} *List;

void printList(List L) {
    if (!L) {
        printf("[]\n");
        return;
    }
    printf("[%d", head(L));
    List curr = tail(L);
    while (curr) {
        printf(", %d", head(curr));
        curr = tail(curr);
    }
    printf("]\n");
}


// Pass in a list, and a function _pointer_.
// Apply the function on each element of the list and set return to newval.
void map (List L, int (*f) (int))
{
	if (!empty (L)) {
		head (L) = (*f) (head (L));
		map (tail (L), f);
	}
}

// Pass in a list, and a function _pointer_ that can be read as:
//     Take in two integers, an accumulator and curr element return new val of accumulator
// 'Smash' a list into an integer via the given f.
int fold (List L, int (*f) (int, int), int z, int level)
{
	if (empty (L)) {
        for (int i = 0; i < level; i++) printf("\t");
        printf("Returned %d on level %d!\n", z, level);
		return z;
	} else {
        for (int i = 0; i < level; i++) printf("\t");
        printf("%dth call of f on head=%d tail=", level, head(L));
        printList(tail(L));
        int accReturned = fold (tail (L), f, z, level+1);
        for (int i = 0; i < level; i++) printf("\t");
        printf("%dth call returned back %d\n", level, accReturned);
		return f (head (L), accReturned);
    }
}

int mult(int x , int y) { return x * y; }

// Just for fun, we're playing code golf
List newListNode(int v) { List n = calloc(1,sizeof(struct _list)); return (head(n)=v,n); }
List prependNode(List L, List n) { return (tail(n) = L, n); }
List prependVal(List L, int v) { return (!L ? newListNode(v) : prependNode(L, newListNode(v))); }

int main(void)
{
    List l = NULL;
    l = prependVal(l, 2);
    l = prependVal(l, 3);
    l = prependVal(l, 4);

    int prod = fold(l, mult, 1, 0);
    printf("Result of 2*3*4 = %d\n", prod);
}