#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define X 140
#define Y 140

// FIND XMAS in vertical and diagonal
// FIND SAMX in veritcal horizontal and diagonal

int main(void) {
    printf("Day One\n");
    FILE* fptr;

    fptr = fopen("../day4.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char data[Y][X];
    char line[X+2];
    char *pch;
    int cnt =0;
    while (fgets(line, X+2, fptr) != NULL) {
      printf("%s", line);
      for (int j = 0; j < X; j++) {
        data[cnt][j] = line[j];
      }
      cnt++;
    }
    printf("\n");
    //horizontal check
    int sum = 0;
    for (int i = 0; i < Y; i++){
        for (int j = 0; j < X-3; j++){
            if (data[i][j] == 'X' & data[i][j+1] == 'M' & data[i][j+2] == 'A' & data[i][j+3] == 'S')
              sum++;
            if (data[i][j] == 'S' & data[i][j+1] == 'A' & data[i][j+2] == 'M' & data[i][j+3] == 'X')
              sum++;
        }
    }

    for (int i = 0; i < Y-3; i++){
        for (int j = 0; j < X; j++){
            if (data[i][j] == 'X' & data[i+1][j] == 'M' & data[i+2][j] == 'A' & data[i+3][j] == 'S')
                sum++;
            if (data[i][j] == 'S' & data[i+1][j] == 'A' & data[i+2][j] == 'M' & data[i+3][j] == 'X')
                sum++;
        }
    }
    for (int i = 0; i < Y -3; i++){
        for (int j = 0; j < X-3; j++){
            if (data[i][j] == 'X' & data[i+1][j+1] == 'M' & data[i+2][j+2] == 'A' & data[i+3][j+3] == 'S')
                sum++;
            if (data[i][j] == 'S' & data[i+1][j+1] == 'A' & data[i+2][j+2] == 'M' & data[i+3][j+3] == 'X')
                sum++;
        }
    }
    for (int i = 0; i < Y-3 ; i++){
        for (int j = 3; j < X; j++){
            if (data[i][j] == 'X' & data[i+1][j-1] == 'M' & data[i+2][j-2] == 'A' & data[i+3][j-3] == 'S')
                sum++;
            if (data[i][j] == 'S' & data[i+1][j-1] == 'A' & data[i+2][j-2] == 'M' & data[i+3][j-3] == 'X')
                sum++;
        }
    }
    printf("Sum = %d\n", sum);
    sum =0;

    for (int i = 0; i < Y-2 ; i++){
        for (int j = 0; j < X-2; j++){
            if ((data[i][j] == 'M' & data[i+1][j+1] == 'A' & data[i+2][j+2] == 'S')||(data[i][j] == 'S' & data[i+1][j+1] == 'A' & data[i+2][j+2] == 'M'))
                if ((data[i][j+2] == 'M' & data[i+2][j] == 'S')||(data[i][j+2] == 'S'  & data[i+2][j] == 'M'))
                sum++;

        }
    }
    printf("Sum = %d\n", sum);


    return 0;
}
