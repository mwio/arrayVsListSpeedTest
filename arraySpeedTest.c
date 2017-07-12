#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//#define kElements 150000
#define kElements 15000000

struct arrayItem {
  int p;
  int q;
  /*char foreName[64];*/
  /*char surname[64];*/
};

int sumArray(struct arrayItem p[], int num) {
  int sum = 0;
  int i;

  for (i = 0; i < num; i++) {
    sum += p[i].p;
  }
  return sum;
}

const char *progress = "-\\|/";

int main(int argc, char **argv) {
  clock_t clk;
  struct arrayItem *a;
  int i;
  int sum;

  int tot = 0;

  printf("Initializing array [-]");
  a = calloc(1, sizeof(struct arrayItem) * kElements);

  /* Generate random number < 100 */
  for (i = 0; i < kElements; i++) {
    if (i % 100 == 0) {
      printf("%c%c%c]",8,8,progress[(i/100) % 4]);
      fflush(stdout);
    }
    a[i].p = random() % 100;
  }
  printf("\n\nTiming...\n");
  for (i = 0; i < 100; i++) {
    clk = clock();
    sum = sumArray(a, kElements);

    clk = clock();
    tot += clk;
    printf("Array %ld ticks, sum %d\n", clk, sum);
  }
  printf("\nAverage time: %f ticks\n", ((double)tot)/100.0);
  getchar();
}
