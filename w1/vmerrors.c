/*
 * A suite of lovely pointer errors to expose you to many potential errors
 * that you WILL face in COMP2521. Theory is great, but even when you have
 * the solution down, coming to code it up is a whole other beast in itself!
 * 
 * Try spot and fix all the errors you see in this file to get the 'expected'
 * behaviour of the program. Each phase is (hopefully) completely independent.
 * 
 * ~arm
 */

#include <stdio.h>
#include <stdlib.h>
#define CACHESIZE 64

int cache[CACHESIZE];   

void printArr(int *arr, int n);
void fillSquares(int *arr, int n);
int search(int *arr, int x, int n);
int binary_search(int *arr, int x, int lo, int hi);
int *TAB();

int main(void)
{
    ///////////// PHASE 1 /////////////

    int x;
    printf("Hey! Give me an integer and I'll square it: ");
    scanf("%d", &x);             // assume valid user input
    printf("%d^2 = %d", x, x*x);

    ///////////// PHASE 2 /////////////

    fillSquares(cache, 48); // 48
    printArr(cache, CACHESIZE); // 64

    int *arr = malloc(sizeof(int) * CACHESIZE);
    if (arr == NULL) {
        fprintf(stderr, "vmerrors: arr failed to allocate");
        return EXIT_FAILURE;
    }
    fillSquares(arr, 48); // 48
    printArr(arr, CACHESIZE); // 64

    ///////////// PHASE 3 /////////////
    printf("Going to construct a %dx%d matrix!\n", CACHESIZE, CACHESIZE);
    int **matrix = (int **) calloc(CACHESIZE, sizeof(int *)); 
    // do checks ...
    for (int i = 0; i <= CACHESIZE; i++) {
        matrix[i] = (int *) calloc(CACHESIZE, sizeof(int));
        // do checks ...
        printArr(matrix[i], CACHESIZE);
    }

    ///////////// PHASE 4 /////////////

    printf("These are just a set of logical puzzles. To each answer in your mind true or false\n");
    printf("Assume x is a signed integer, and ux is an unsigned integer.\n");  

    printf("Does the condition x > 0 ==> x * 2 > 0\n");
    printf("Does x > 0 && y > 0 ==> x + y > 0\n");
    printf("Is ux >= 0 for all possible values of ux? i.e. can ux be negative?\n");
    printf("Run code: ux = x. Is ux == x true?\n");
    printf("Last one: What will this print statement print? %d\n", *TAB());

    ///////////// PHASE 5 /////////////

    int n_arr[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    int integerToSearch = 23;
    printf("Is %d in arr? %d\n", integerToSearch, search(n_arr, integerToSearch, 10));
    // ? Hint! The error is in binary_search and is commonly known as an off by one error.
    // ? There are more bugs than just that off by one error though!
    // ? Without running this phase, try to simulate what will happen.
}

int *TAB()
{
    int x = 3;
    return &x;
}

int search(int *arr, int x, int n)
{
    return binary_search(arr, x, 0, n-1);
}

/*
 * binary_search: 'fast' implementation of search
 *      Precondition: array must be in sorted order
 *      Postcondition: if the array contains the 'x', return 1 else 0
 *                     array is not mutated in any way (i.e. read perms only)
 */
int binary_search(int *arr, int x, int lo, int hi)
{
    // if the left hand side of the array we're looking is right of the rhs?
    // that doesn't make any sense, so that must mean our x doesn't exist!
    if (lo > hi) return 0;

    // look at the middle of the sorted array[lo..hi]
    int mid = (lo+hi) / 2;

    // check if the middle is our x we're looking for
    if (arr[mid] == x) return 1;

    // okay, so the middle is not our x. Well since our array is sorted this can go two ways.
    // (1) if our x is less than the arr[mid], then it must be in the range from [0..mid]
    // (2) otherwise, our x must be on the rhs of arr[mid] as it's greater than arr[mid]
    if (x < arr[mid]) binary_search(arr, x, lo, mid);
    else binary_search(arr, x, mid, hi);
}

void printArr(int *arr, int n)
{
    if (n == 0) return;
    printf("Array: %d", arr[0]);
    for (int i = 1; i < n; i++) {
        printf("| %d", arr[i]);
    }
    printf("\n");
}

void fillSquares(int *arr, int n)
{
    for (int i = 0; i < n; i++) {
        arr[i] = i * i;
    }
}
