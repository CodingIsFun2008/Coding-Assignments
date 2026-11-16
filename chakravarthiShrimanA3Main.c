#include "givenA3.h"

int main () {

   FILE * fileInput = NULL;

   char stop[MAX_STOP][MAX_WORD];
   char variant[MAX_LEMMA][MAX_WORD];
   char lemma[MAX_LEMMA][MAX_WORD];
   char post[MAX_POSTS][MAX_LEN];

   int numPosts;
   int numStops;
   int numLemma;

   char filename [20];

   printf ("Enter filename: ");
   scanf ("%s", filename);

   fileInput = fopen(filename, "r");
   numPosts = readInput(fileInput, stop, &numStops, variant, lemma, &numLemma, post);

   // call other functions here

   char tokens[MAX_TOKENS][MAX_WORD];
   char work[MAX_LEN];
   int numToken;
   int sentenceNum;
   int i;
   int k;

   printf("Enter number of inputs: ");
   scanf("%d", &sentenceNum);

   for (i = 0; i < sentenceNum && i < numPosts; i++) {
                   printf("Post %d original: %s\n", i + 1, post[i]);

                   strcpy(work, post[i]);
                   normalize(work);

                   numToken = tokenize(work, tokens);
                   printf("Number of tokens = %d\n", numTokens);

                   tokensAfterStop = removeStopWords(tokens, numToken, stop, numStops);
                   printf("Num of stop words removed = %d\n, numToken - tokensAfterStop);

                   applyLemmaMap(tokens, numToken, variant, lemma, numLemma);

                   printf("Post %d cleaned: ", i + 1);

                   for (k = 0; k < tokensAfterStop; k++) {
                            printf("%s", tokens[k]);

                            if (k < tokensAfterStop - 1) {
                                    printf(" ");
                            }
                   }
                   printf("\n");
   }

   fclose (fileInput);
   return 0;
}

/************************chakravarthiShrimanA3Main.c**************
Student Name: Shriman Chakravarthi Email Id: 1417097
Due Date: November 11 Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity. 2) I
have completed the Computing with Integrity Tutorial on Moodle; and 3) I have
achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.
********************************************************/
