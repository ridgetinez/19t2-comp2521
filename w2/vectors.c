#include <stdio.h>
#include <stdlib.h>

/* Vector imp. is attributed to Nicholas Hiebl: github.com/nick-hiebl */

typedef struct _node {
  int index;
  double value;
  struct _node *next;
} *Node;

typedef struct _vector {
  Node first;
  Node last;
  int dimension;
} *Vector;

Vector addVectors(Vector a, Vector b);

void showVector(Vector v) {
  Node curr = v->first;
  int i = 0;
  printf("(");
  while (i < v->dimension) {
    if (curr != NULL && curr->index == i) {
      printf("%.2lf,", curr->value);
      curr = curr->next;
    } else {
      printf("0.00,");
    }
    i++;
  }
  printf(")\n");
}

Vector newVector(int dimension) {
  Vector v = malloc(sizeof(struct _vector));
  v->dimension = dimension;
  v->first = NULL;
  v->last = NULL;
  return v;
}

void freeList(Node n) {
  Node next = n->next;
  free(n);
  if (next != NULL) freeList(next);
}

void freeVector(Vector v) {
  freeList(v->first);
  free(v);
}

Node newNode(double v, int i) {
  Node node = malloc(sizeof(struct _node));
  node->index = i;
  node->value = v;
  node->next = NULL;
  return node;
}

void appendNode(Vector v, Node n) {
  if (v->first == NULL) {
    v->first = v->last = n;
  } else {
    v->last->next = n;
    v->last = n;
  }
}

// Complexity?
Vector addVectors(Vector v, Vector w) {
    /*
     * Take inspiration from the O(n) merge function of two sorted lists into one sorted list.
     * When traversing through the two vectors, what cases might we have to consider?
     */
    if (v->dimension != w->dimension) return NULL;
    Vector sumV = newVector(v->dimension);
    Node currV = v->first;
    Node currW = w->first;
    while(currV != NULL && currW != NULL) {
      // Cases:
      // (1) When the index you're comparing (currV->index == currW->index) are equal
      // (2) When one index is less than the other (currV->index > currW->index), just append and move currW forward
      // (3) Otherwise, append and move currV forward
      if (currV->index == currW->index) {
        // if we add the values of both the heads and they give us zero, don't want to append (e.g. 2 + -2 = 0)
        if (currV->value + currW->value != 0) {
          appendNode(sumV, newNode(currV->value + currW->value, currV->index));
        }
        currV = currV->next;
        currW = currW->next;
      } else if (currV->index < currW->index) {
        appendNode(sumV, newNode(currV->value, currV->index));
        currV = currV->next;
      } else {
        appendNode(sumV, newNode(currW->value, currW->index));
        currW = currW->next;
      }
    }
    // in the case that we still have values left to append to our new list
    while (currV != NULL) {
      appendNode(sumV, newNode(currV->value, currV->index));
      currV = currV->next;
    }
    while (currW != NULL) {
      appendNode(sumV, newNode(currW->value, currW->index));
      currW = currW->next;
    }
    return sumV;
}

int main(void) {
  Vector v1 = newVector(8);
  appendNode(v1, newNode(2.3, 0));
  appendNode(v1, newNode(-0.1, 1));
  appendNode(v1, newNode(1.7, 4));
  
  Vector v2 = newVector(8);
  appendNode(v2, newNode(3.14, 1));
  appendNode(v2, newNode(-1.7, 4));
  appendNode(v2, newNode(-1.8, 7));

  showVector(v1);
  showVector(v2);

  Vector sum = addVectors(v1, v2);
  showVector(sum);

  freeVector(v1);
  freeVector(v2);

  return EXIT_SUCCESS;
}
