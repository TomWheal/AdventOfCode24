#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INSTRUCTIONS 2000

int main(void) {
    printf("Day Five\n");
    FILE* fptr;

    fptr = fopen("../day5.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    char insA[INSTRUCTIONS][3];
    char insB[INSTRUCTIONS][3];

    char line[500];
    char *pchA;
    char *pchB;
    int i =0;
    while (fgets(line, 500, fptr) != NULL) {
        if (line[0] == '\n')
            break;
        strncpy(insA[i], line,2);
        insA[i][2] = '\0';
        strncpy(insB[i], line+3,2);
        insB[i][2] = '\0';

        i++;
    }
//    for (int j = 0; j < i; j++) {
//      printf("%s , %s\n", insA[j],insB[j]);
//    }
    long sumA = 0;
    long sumB = 0;
    while (fgets(line, 500, fptr) != NULL) {
        int length = strlen(line);
        int pass = 1;
        char midNum[3];
        for (int j = 0; j < i; j++) {
            pchA = strstr(line,insA[j]);
            pchB = strstr(line,insB[j]);
            if (pchA != NULL && pchB != NULL) {
              if(pchB<pchA){
                  pass = 0;
                  printf("Fail:");
                  break;
              }
            }
        }
        if (pass) {
          strncpy(midNum, line+((length-3)/2),2);
          midNum[2] = '\0';
          sumA += atol(midNum);
        }
        else{
          char tmp[2];
            for (int jj = 0; jj < i; jj++) {
                for (int j = 0; j < i; j++) {
                    pchA = strstr(line,insA[j]);
                    pchB = strstr(line,insB[j]);
                    if (pchA != NULL && pchB != NULL) {
                        if(pchB<pchA){
                            strncpy(tmp,pchA,2);
                            strncpy(pchA,pchB,2);
                            strncpy(pchB,tmp,2);
                        }
                    }
                }
            }
            //printf(line);
            strncpy(midNum, line+((length-3)/2),2);
            midNum[2] = '\0';
            //printf("%s\n", midNum);
            sumB += atol(midNum);
          }

    }
    printf("\n");
    printf("Part A: %ld\n", sumA);
    printf("Part B: %ld\n", sumB);
    return 0;
}
