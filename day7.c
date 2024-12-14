//
// Created by Thomas Wheal on 07/12/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long concatenate(unsigned long  long x, unsigned long long y) {
    unsigned long long pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;
}

//0 0 0 0 0
//0 0 0 0 1
//0 0 0 0 2
//0 0 0 1 0
//0 0 0 1 1
//0 0 0 2 0
//0 0 0 2 1


long long check1(long target, int *arr, int size) {
    int cnt = 0;
    static int tests[1000000][12+1];
    for(int i = 0; i < size+1; i++) {
        tests[0][i] = 0;
    }
    do {
        cnt++;
        tests[cnt][0] = tests[cnt-1][0] +1;
        for (int i = 1; i < size+1; i++) {
            if (tests[cnt][i-1]==3) {
                tests[cnt][i] = tests[cnt-1][i] + 1;
                tests[cnt][i-1] = 0;
            }
            else
                tests[cnt][i] = tests[cnt-1][i];
        }
        for (int i = size ; i >= 0; i--) {
            //printf("%d ", tests[cnt][i]);
        }
        //printf("\n");
    }while (tests[cnt][size]!=1);
    //printf("Count is %d\n", cnt);

    for (int i = 0; i < cnt-1; i++) {
        long total =arr[0];
        for (uint32_t j = 0; j < size-1; j++) {
            if (tests[i][j]==0)
                total*=arr[j+1];
            else if (tests[i][j]==1)
                total+=arr[j+1];
            else if (tests[i][j]==2)
                total = concatenate(total, arr[j+1]);
        }
        if (total == target)
            return target;
    }
    return 0;
}

int main(void) {
    printf("Day 7\n");

    FILE* fptr = fopen("test.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    long long partA_sum =0;
    char line[1000];
    char * pch;
    int big_line =0;
    while (fgets(line, 1000, fptr) != NULL) {
        int num_cnt = 0;
        long target = 0;
        int nums[100];
        pch = strtok(line, ":");
        target = atol(pch);
        pch = strtok(NULL, " ");
        while (pch != NULL) {
            nums[num_cnt] = atol(pch);
            pch = strtok(NULL, " ");
            num_cnt++;
        }
        if (num_cnt>big_line)
            big_line = num_cnt;
        printf("Target: %li, Nums %i\n", target,num_cnt);
        for (int i = 0; i < num_cnt; i++) {
            printf("%d,", nums[i]);
        }
        printf("\n");
        partA_sum += check1(target, nums, num_cnt);
    }
    printf("Big line is %d\n", big_line);
    printf("Part A Sum = %lli\n",partA_sum);
    return 0;
}