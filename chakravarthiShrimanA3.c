#include <stdio.h>

#include "givenA3.h"

#include <ctype.h>

#include <string.h>

/************************chakravarthiShrimanA3.c**************
Student Name: Shriman Chakravarthi Email Id: 1417097
Due Date: November ... Course Name: CIS 1300
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

// REMEMBER to change this file name to the required format of lastnameFirstnameA3.c

// function definition of readInput

int readInput(FILE * inputData,
                char stop[][MAX_WORD],
                int * numStop,
                char variant[][MAX_WORD],
                char lemma[][MAX_WORD],
                int * numLemma,
                char post[][MAX_LEN]) {


   int i;
   int num;
   char line [MAX_LEN];

   // read num of stop words

   fscanf(inputData, "%d", &num);
   fgetc(inputData);

   *numStop = num;

   // read the stop words

   for (i = 0; i < num; i++) {
      fgets (line, MAX_LEN, inputData);
      line [strlen (line) - 1] = '\0';
      strcpy( stop[i],line);
   }

   // repeat the same as above for lemma pairs

   fscanf(inputData, "%d", &num);
   fgetc(inputData);

   *numLemma = num;

   for (i = 0; i < num; i++) {
      fgets (line, MAX_LEN, inputData);        // read the variant
      line [strlen (line) - 1] = '\0';
      strcpy( variant[i],line);

      fgets (line, MAX_LEN, inputData);        // read the lemma
      line [strlen (line) - 1] = '\0';
      strcpy( lemma[i],line);
   }

   // repeat the same as above for posts

   fscanf(inputData, "%d", &num);
   fgetc(inputData);

   for (i = 0; i < num; i++) {
      fgets (line, MAX_LEN, inputData);
      line [strlen (line) - 1] = '\0';
      strcpy( post[i],line);
   }

   return num;          // return num of posts read
}

// define all other functions here

void normalize(char line[]) {

      int len = strlen(line);
      int i;

      for (i = 0; i < len; i++) {
             line[i] = tolower((unsigned char)line[i]);

             switch(line[i]) {
                 case '.':
                 case ',':
                 case '!':
                 case '?':
                 case ':':
                 case ';':
                 case '"':
                 case '(':
                 case ')':
                 case '[':
                 case ']':
                     line[i] = ' ';
                     break;
                default:
                     break;
             }
     }

     return line[];
}

int tokenize (const char line[], char tokens[][MAX_WORD]) {

      int len = 0;
      int count = 0;

      for (i = 0; i != '\0', i++) {
             if (!isspace(line[i])) && !isspace((unsigned char(line[i]))) {
                  if (len < (MAX_WORD - 1)) {
                           tokens[count][len] = line[i];
                           len++;
                  }

                  else {
                     if (len > 0) {
                            words[count][len] = '\0';
                            count++;
                            len = 0;

                            if (count == MAX_WORD) {
                                   break;
                            }
                    }


                     if (line[i] == '\0') {
                            break;
                     }
                  }
              }
      }

      return count;
}

int removeStopWords (char tokens[][MAX_WORD], int numToken, char stop[][MAX_WORD], int numStop) {
                           int i;
                           int newCount;
                           int j;
                           int isStop;

                           for (i = 0; i < numStop; i++) {
                                      isStop = 0;

                                for (j = 0; j < numStop; j++) {
                                         if (strcmp(tokens[i], stop[j]) == 0) {
                                                    isStop = 1;
                                                    break;
                                         }
                                }

                                if (!isStop) {
                                      if (newCount != i) {
                                         strcpy(tokens[newCount], tokens[i]);
                                      }

                                      newCount++;
                               }
                           }

                           return newCount;
}

void applyLemmaMap(char tokens[][MAX_WORD], int count, char variant[][MAX_WORD], char lemma[][MAX_WORD], int L) {

                                  int i;
                                  int j;

                                  for (i = 0; i < count; i++) {
                                              for (j = 0; j < L; j++) {
                                                         if (strcmp(tokens[i], variant[j]) == 0) {
                                                                    strcpy(tokens[i], lemma[j]);
                                                                    break;
                                                         }
                                               }
                                  }
}
