//
// Created by Thomas Wheal on 14/12/2024.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

typedef int64_t i64;
typedef uint64_t u64;

#define A_COST 3
#define B_COST 1


long solve(i64 xa,i64 ya,i64 xb,i64 yb,i64 xp,i64 yp) {

    i64 a1  = (xp*yb - yp*xb);
    i64 a2 = ( xa*yb - ya*xb );

    i64  b1  =  (xp*ya - yp*xa);
    i64  b2 =    (xb*ya - yb*xa);

    if (a1%a2 ==0 && b1%b2 ==0) {
      a1 = a1/a2;
      b1 = b1/b2;
      if (a1 >=0 && b1 >=0) {
        printf("a1 = %ld, b1 = %ld\n", a1, b1);
        return 3*a1 + b1;
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

  i64 xa = 0;
  i64 xb = 0;
  i64 ya = 0;
  i64 yb = 0;

  i64 xp = 0;
  i64 yp = 0;
  i64 t1 = 0;
  i64 t2 = 0;

  char line[1000];
  char * pch;
  while (fgets(line, 1000, fptr) != NULL) {
    if (line[7] == 'A') {
      pch = strtok(line, "+");
      pch = strtok(NULL, ",");
      xa = strtoll(pch, NULL, 10);
      pch = strtok(NULL, "+");
      pch = strtok(NULL, "+");
      ya = strtoll(pch, NULL, 10);
    } else
    if (line[7] == 'B') {
      pch = strtok(line, "+");
      pch = strtok(NULL, ",");
      xb = strtoll(pch, NULL, 10);
      pch = strtok(NULL, "+");
      pch = strtok(NULL, "+");
      yb = strtoll(pch, NULL, 10);
    }
    else
    if (line[0] == 'P') {
      pch = strtok(line, "=");
      pch = strtok(NULL, ",");
      xp = strtoll(pch, NULL, 10) ;
      pch = strtok(NULL, "=");
      pch = strtok(NULL, "=");
      yp = strtoll(pch, NULL, 10) ;
      printf("xa = %ld, xb = %ld\n", xa, xb);
      printf("ya = %ld, yb = %ld\n", ya, yb);
      printf("xp = %ld\n", xp);
      printf("yp = %ld\n", yp);
      t1 += solve(xa, ya, xb, yb, xp, yp);
      xp += 10000000000000;
      yp += 10000000000000;
      t2 += solve(xa, ya, xb, yb, xp, yp);

    }

  }
    printf("Part 1: %lli\n", t1);
  printf("Part 2: %lli\n", t2);
  fclose(fptr);
  return 0;
}