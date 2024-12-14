//
// Created by Thomas Wheal on 14/12/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <math.h>
#include <time.h>
#define SIZE_X 101
#define SIZE_Y 103
#define DURATION 1000000
#define LINES 500

int64_t pos_calc(int64_t p, int64_t v, uint64_t size, uint32_t duration) {
 for (int i =0; i<duration; i++) {
     p = (p + v);
     p = p<0? p+size:p;
     p = p>=size?p-size:p;
 }
    return p;
}

void print_map(int64_t *px, int64_t *py) {
    uint8_t map[SIZE_X][SIZE_Y];
    for (int i = 0; i < SIZE_X; i++) {
        for (int j = 0; j < SIZE_Y; j++) {
            map[i][j] = 0;
        }
    }
    for (int i=0; i<LINES; i++) {
        map[px[i]][py[i]] = 1;
    }
    for (int i = 0; i < SIZE_Y; i++) {
        for (int j = 0; j < SIZE_X; j++) {
            if (map[j][i] == 1)
                printf("██");
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}


uint64_t mean_calc(int N, int64_t * arr) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    return sum/N;
}

float stan_dev(int N, int64_t * arr) {


    float mean = mean_calc(N,arr);
    float values = 0;

    for (int i = 0; i < N; i++) {
        values += pow(arr[i] - mean, 2);
    }

    float variance = values / N;

    float standardDeviation = sqrt(variance);
    return(standardDeviation);
}

int main() {


    printf("Day 14\n");

    FILE* fptr = fopen("test.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    uint64_t suma =0;
    uint64_t sumb =0;
    uint64_t sumc =0;
    uint64_t sumd =0;

    char line[1000];
    char * pch;
    int64_t px[LINES];
    int64_t py[LINES];
    int64_t px_new[LINES];
    int64_t py_new[LINES];
    int64_t vx[LINES];
    int64_t vy[LINES];
    int i =0;


    while (fgets(line, 1000, fptr) != NULL) {
        pch = strtok(&line[2], ",");
        px[i] = strtol(pch,NULL,10);
        pch = strtok(NULL, " ");
        py[i] = strtol(pch,NULL,10);
        //printf("px: %ld, py: %ld\n", px, py);
        pch = strtok(NULL, "=");
        pch = strtok(NULL, ",");
        vx[i] = strtol(pch,NULL,10);
        pch = strtok(NULL, ",");
        vy[i] = strtol(pch,NULL,10);
        //printf("vx: %li, vy: %li\n", vx, vy);
        i++;
    }
    uint32_t time =0;
     for (int i =0; i<LINES; i++){
        for (time = 0; time < 100; time++) {

            px_new[i] = pos_calc(px[i], vx[i], SIZE_X, time);
            py_new[i] = pos_calc(py[i], vy[i], SIZE_Y,time);

        }
        if (px_new[i]<SIZE_X/2 && py_new[i]<SIZE_Y/2)
            suma ++;
        if (px_new[i]>SIZE_X/2 && py_new[i]<SIZE_Y/2)
            sumb ++;
        if (px_new[i]<SIZE_X/2 && py_new[i]>SIZE_Y/2)
            sumc ++;
        if (px_new[i]>SIZE_X/2 && py_new[i]>SIZE_Y/2)
            sumd ++;
    }
    //print_map(px_new, py_new);
    printf("Suma: %ld\n", suma);
    printf("Sumb: %ld\n", sumb);
    printf("Sumc: %ld\n", sumc);
    printf("Sumd: %ld\n", sumd);
    printf("Saftey Factor: %ld\n",suma*sumb*sumc*sumd);
    for (int i = 0; i < LINES; i++) {
        px_new[i] = px[i];
        py_new[i] = py[i];
    }

    for (time = 0; time < DURATION; time++) {
        suma = 0;
        sumb = 0;
        sumc = 0;
        sumd = 0;
        for (int i =0; i<LINES; i++) {
            px_new[i] = pos_calc(px_new[i], vx[i], SIZE_X, 1);
            py_new[i] = pos_calc(py_new[i], vy[i], SIZE_Y,1);

        }
        float stdev_x = stan_dev(LINES, px_new);
        float stdev_y = stan_dev(LINES, py_new);
        float mean_x = mean_calc(LINES, px_new);
        float mean_y = mean_calc(LINES, py_new);
        // printf("sd x: %f\n", stdev_x);
        // printf("sd y: %f\n", stdev_y);
        // printf("mean x: %f\n", mean_x);
        // printf("mean y: %f\n", mean_y);
        // if (time == 6618)
        //     print_map(px_new, py_new);
        if (mean_x > SIZE_X/2 +5 && mean_y > SIZE_Y/2 + 5 ) {
                print_map(px_new, py_new);
                printf("Time elapsed: %ld\n", time+1);
                return 0;
        }


    }


    return 0;
}