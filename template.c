//
// Created by Thomas Wheal on 14/12/2024.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>


int main(void) {
    printf("Day X\n");

    FILE* fptr = fopen("test.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }


    char line[1000];
    while (fgets(line, 1000, fptr) != NULL) {

    }
fclose(fptr);
return 0;
}