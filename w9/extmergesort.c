#include <stdio.h>
#include <stdlib.h>

// assumes N = 2^k for some integer k > 0
// inFile is the name of the input file
//   - inFile contains sorted sequences of Items of length runLength
// outFile is the name of the output file
//   - outFile will contain sorted sequences of Items of length 2*runLength
// N is the total number of Items

typedef char Item;

#define less(c1, c2) ((c1) < (c2))
/* 
void fileMerge(char *in, char *out, int runLength, int N)
{
    FILE *inf1 = fopen(in, "r");
    FILE *inf2 = fopen(in, "r");
    FILE *outf = fopen(out, "w");
    
    int end1, end2;
    int in1 = 0, in2 = runLength;
    Item it1, it2;
    while (in1 < N) {
        end1 = in1+runLength;
        end2 = in2+runLength;
        fseek(inf1, in1*sizeof(Item), SEEK_SET);
        fread(&it1, sizeof(Item), 1, inf1);
        fseek(inf2, in2*sizeof(Item), SEEK_SET);
        fread(&it2, sizeof(Item), 1, inf2);
        while (in1 < end1 && in2 < end2) {
            printf("it1: %c, it2: %c\n", it1, it2);
            if (less(it1, it2)) {
                fwrite(&it1, sizeof(Item), 1, outf);
                fread(&it1, sizeof(Item), 1, inf1);
                in1++;
            } else {
                fwrite(&it2, sizeof(Item), 1, outf);
                fread(&it2, sizeof(Item), 1, inf2);
                in2++;
            }
        }
        while (in1 < end1) {
            fwrite(&it1, sizeof(Item), 1, outf);
            fread(&it1, sizeof(Item), 1, inf1);
            in1++;
        }
        while (in2 < end2) {
            fwrite(&it2, sizeof(Item), 1, outf);
            fread(&it2, sizeof(Item), 1, inf2);
            in2++;
        }
        in1 += runLength; in2 += runLength;
    }
    fclose(inf1);
    fclose(inf2);
    fclose(outf);
}
*/
void fileMerge(FILE *in, FILE *out, int runLength, int N)
{
    printf("Runlength = %d\n", runLength);
    fseek(out, 0, SEEK_SET);
    int end1, end2;
    int in1 = 0, in2 = runLength;
    Item it1, it2;
    while (in1 < N) {
        end1 = in1+runLength;
        end2 = in2+runLength;
        fseek(in, in1*sizeof(Item), SEEK_SET);
        fread(&it1, sizeof(Item), 1, in);
        fseek(in, in2*sizeof(Item), SEEK_SET);
        fread(&it2, sizeof(Item), 1, in);
        while (in1 < end1 && in2 < end2) {
            printf("it1: %c, it2: %c\n", it1, it2);
            if (less(it1, it2)) {
                fwrite(&it1, sizeof(Item), 1, out);
                fseek(in, (in1+1)*sizeof(Item), SEEK_SET);
                fread(&it1, sizeof(Item), 1, in);
                in1++;
            } else {
                fwrite(&it2, sizeof(Item), 1, out);
                fseek(in, (in2+1)*sizeof(Item), SEEK_SET);
                fread(&it2, sizeof(Item), 1, in);
                in2++;
            }
        }
        while (in1 < end1) {
            fwrite(&it1, sizeof(Item), 1, out);
            fseek(in, (in1+1)*sizeof(Item), SEEK_SET);
            fread(&it1, sizeof(Item), 1, in);
            in1++;
        }
        while (in2 < end2) {
            fwrite(&it2, sizeof(Item), 1, out);
            fseek(in, (in2+1)*sizeof(Item), SEEK_SET);
            fread(&it2, sizeof(Item), 1, in);
            in2++;
        }
        in1 += runLength; in2 += runLength;
    }
}

int main(int argc, char **argv)
{
   if (argc != 4) {
      fprintf(stderr, "usage: %s <fileA> <fileB> <N>\n", argv[0]);
      return 1;
   }
   int runLength = 1;   // runlength denotes the number of elements we should consider to be sorted
                        // at initialisation, we consider sorted lists of 1 element,
                        // during merge we merge two sequences of runlength length forming
                        // a 2 * runlength sorted sequence much like in-memory mergesort
   int iter = 0;
   int N = atoi(argv[3]);
   FILE *f1 = fopen(argv[1], "r+");
   FILE *f2 = fopen(argv[2], "r+");
   FILE *in, *out;
   while (runLength < N) {
      if (iter % 2 == 0) { in = f1; out = f2; }
      else { in = f2; out = f1; }
      fileMerge(in, out, runLength, N);
      iter++;
      runLength *= 2;
   }
}

/*
copy stdin file to A
runLength = 1
iter = 0
while (runLength < N) {
   if (iter % 2 == 0)
      inFile = A, outFile = B
   else
      inFile = B, outFile = A
   fileMerge(inFile, outFile, runLength, N)
   iter++;
   runLength *= 2;
}
copy outfile to stdout
*/