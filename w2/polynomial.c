/*
 * Adrian Martinez
 * adrian.martinez@unsw.edu.au
 *
 * An O(n) algorithm, that's easiest to implement recursively, solving
 * polynomial evaluation at a given point x (one variable).
 */

#include <stdio.h>
#include <stdlib.h>

double eval_polynomial_iter(double *, int, double); 

int main(int argc, char **argv) {
    if (argc <= 1) {
      fprintf(stderr, "Give coefficients as command-line arguments\n");
      return EXIT_FAILURE;
    }

    double *coefficients;
    int n = argc - 1;
    coefficients = malloc(n * sizeof(double));
    int i;
    for (i = 1; i < argc; i++) {
      coefficients[i-1] = atof(argv[i]);
    }

    printf("%.2lf", coefficients[0]);
    for (i = 1; i < n; i++) {
      printf(" + %.2lfx^%d", coefficients[i], i);
    }
    printf("\nx = ");

    double x;
    scanf("%lf", &x);

    double f_x = eval_polynomial_iter(coefficients, n, x);

    printf("f(x) = %lf\n", f_x);
}

double eval_polynomial_iter(double *coeff, int n, double x) {
    /* Todo :) */
}

// Use the fact that a_0 + a_1x + a_2x^2 + .. + a_n-1x^n-1
//                 = a_0 + x(a_1 + x(a_2 + ... x(a_n-1)))
double horner(double *coeff, int n, int i, double x) {
    /* Todo :) */
}