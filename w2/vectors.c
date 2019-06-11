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
    /* Implement me :)
     * Take inspiration from the O(n) merge function of two sorted lists into one sorted list.
     * When traversing through the two vectors, what cases might we have to consider?
     */
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
