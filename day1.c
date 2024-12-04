#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 1000


void sort(int *arr) {
    int temp;
    for (int i = 0; i < COUNT; i++) {
        for (int j = 0; j < COUNT-1 ; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int count(int *arr,int num) {
    int cnt=0;
    for (int i = 0; i < COUNT; i++) {
        if (arr[i] == num) {
            cnt++;
        }
    }
    return cnt;
}


int main(void) {
    printf("Day One\n");
    FILE* fptr;

    fptr = fopen("../day1.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    int cnt =0;
    char line[100];
    int num1[COUNT];
    int num2[COUNT];
    char *pch;
    while (fgets(line, 100, fptr) != NULL) {
        strtok(line, "   ");
        num1[cnt] = atoi(line);
        num2[cnt] = atoi(strtok(NULL, "   "));
        cnt++;
    }
    // for (int i = 0; i < COUNT; i++) {
    //     printf("%i:%i\n",num1[i],num2[i]);
    // }
    sort(num1);
    sort(num2);
    long long int sum = 0;
    for (int i = 0; i < COUNT; i++) {
        sum+= abs(num1[i] - num2[i]);
    }
    printf("Part 1 Total Distance = %d\n", sum);
    int similarity =0;
    for (int i = 0; i < COUNT; i++) {
        similarity += num1[i]*count(num2, num1[i]);
    }
    printf("Part 2 Similarity = %d\n", similarity);
    return 0;
}
