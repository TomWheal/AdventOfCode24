#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_DIFF 1
#define MAX_DIFF 3




// safe if they are all increasing or all decreasing
// incrementing by 1 - 3
// the number of numbers differs
// check they are all in the same direction

int check1(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size-1; i++) {
        if (arr[i] < arr[i + 1])
            sum ++;
        else if ((arr[i] > arr[i + 1]))
            sum --;
    }

    return abs(sum)!=size-1;
}

int check2(int *arr, int size) {
    int err = 0;
    for (int i = 0; i < size-1; i++) {
        if (abs(arr[i] - arr[i + 1])>3)
            err ++;
    }

    return err;
}

int main(void) {
    printf("Day Two\n");

    FILE* fptr;

    fptr = fopen("../day2.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int safe_cnt = 0;
    int damper_cnt = 0;
    char line[100];
    int line_num = 0;
    char * pch;
    int report[10];
    while (fgets(line, 100, fptr) != NULL) {
        int num_cnt = 0;
        int safe = 0;
        pch = strtok(line, " ");
        while (pch != NULL) {
            report[num_cnt] = atoi(pch);
            pch = strtok(NULL, " ");
            num_cnt++;
        }

        if (check1(report, num_cnt)==0) {
            //printf("Line %d is safe cnt %d\n", line_num,num_cnt);
            if (check2(report, num_cnt)==0) {
                printf("Line %d is safe cnt %d\n", line_num,num_cnt);
                safe =1;
                safe_cnt ++;
            }

        }
        if (safe ==0)
            for (int i = 0; i < num_cnt; i++) {
                int temp_report[10];
                int j =0;
                int jj=0;
                do {
                    if (j!=i) {
                        temp_report[jj] = report[j];
                        jj++;
                    }
                    j++;
                } while (j<num_cnt);
                if (check1(temp_report, num_cnt-1)==0) {
                    //printf("Line %d is safe cnt %d\n", line_num,num_cnt);
                    if (check2(temp_report, num_cnt-1)==0) {
                        printf("Line %d is safe with damper cnt %d\n", line_num,num_cnt);
                        safe =1;
                        damper_cnt ++;
                    }

                }
                if (safe)
                    break;
            }
        //strtok(line, "   ");
        line_num++;
    }

    printf("Total Lines = %i \n",line_num);
    printf("Safe Cnt = %i \n",safe_cnt);
    printf("Safe Damper Cnt = %i \n",damper_cnt+safe_cnt);
    return 0;
}