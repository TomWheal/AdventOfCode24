//
// Created by Thomas Wheal on 14/12/2024.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef int64_t i64;
typedef uint64_t u64;

#define MAX_TRY 100000000
#define A_COST 3
#define B_COST 1


u64 solve(i64 a_x,i64 a_y,i64 b_x,i64 b_y,i64 x_prize,i64 y_prize) {
  // Prioritise B as its cheaper
  u64 cnta = 0;
  u64 cntb = 0;


    cnta = (x_prize*b_y - y_prize*b_x) / (a_x*b_y - a_y*b_x);
    cntb = (x_prize*a_y - y_prize*a_x) / (b_x*a_y - b_y*a_x);
    //cnta = (x_prize - cntb*b_x)/a_x;

  if (cnta*a_x +cntb*b_x == x_prize) {
    if (cnta*a_y +cntb*b_y == y_prize) {
      return 3*cnta + cntb;
    }

  }
  return 0;

}

int main(void) {
  printf("Day X\n");

  FILE* fptr = fopen("test.txt", "r");
  if (fptr == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  i64 a_x = 0;
  i64 b_x = 0;
  i64 a_y = 0;
  i64 b_y = 0;

  i64 x_prize = 0;
  i64 y_prize = 0;
  u64 t1 = 0;
  u64 t2 = 0;

  char line[1000];
  char * pch;
  while (fgets(line, 1000, fptr) != NULL) {
    if (line[7] == 'A') {
      pch = strtok(line, "+");
      pch = strtok(NULL, ",");
      a_x = strtoll(pch, NULL, 10);
      pch = strtok(NULL, "+");
      pch = strtok(NULL, "+");
      a_y = strtoll(pch, NULL, 10);
    } else
    if (line[7] == 'B') {
      pch = strtok(line, "+");
      pch = strtok(NULL, ",");
      b_x = strtoll(pch, NULL, 10);
      pch = strtok(NULL, "+");
      pch = strtok(NULL, "+");
      b_y = strtoll(pch, NULL, 10);
    }
    else
    if (line[0] == 'P') {
      pch = strtok(line, "=");
      pch = strtok(NULL, ",");
      x_prize = strtoll(pch, NULL, 10) ;
      pch = strtok(NULL, "=");
      pch = strtok(NULL, "=");
      y_prize = strtoll(pch, NULL, 10) ;
      t1 += solve(a_x, a_y, b_x, b_y, x_prize, y_prize);
      t2 += solve(a_x, b_y, b_x, a_y, x_prize+10000000000000, y_prize+10000000000000);
    }

  }
    printf("Part 1: %llu\n", t1);
  printf("Part 2: %llu\n", t2);
  fclose(fptr);
  return 0;
}