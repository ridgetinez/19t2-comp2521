#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Complexity? Iteration vs. recursion tradeoffs */

int isPalindromeIter(char *word) {
    int n = strlen(word); 
    for (int i = 0; i < n/2; i++) {
      if (word[i] != word[n-i-1]) return 0;
    }
    return 1;
}

int isPalindromeRec(char *word, int lo, int hi)
{
    if (lo >= hi) return 1;
    return word[lo] == word[hi] && isPalindromeRec(word, lo+1, hi-1);
}

/* Main code attributed to Nicholas Hiebl: github.com/nick-hiebl */
int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Correct usage: %s <word>\n", argv[0]);
    return EXIT_FAILURE;
  }

  if (isPalindrome(argv[1])) {
    printf("yes\n");
  } else {
    printf("no\n");
  }

  return EXIT_SUCCESS;
}

