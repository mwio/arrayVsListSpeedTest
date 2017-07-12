#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//#define kElements 150000
#define kElements 15000000

struct item {
  int p;
  int q;
  /*char foreName[64];*/
  /*char surname[64];*/
  struct item *next;
};

int sumList(struct item *p) {
  int sum = 0;
  int i = 0;

  //while(p->next != NULL && i <= kElements) {
  while(p != NULL) {
	sum += p->p;
    p = p->next;
    //i++;
  }
  return sum;
}

const char *progress = "-\\|/";

int main(int argc, char **argv) {
  clock_t clk;
  struct item *a = NULL, *p, *q;
  int i;
  int sum;
  int tot = 0;

  printf("Initializing list [-]");
  // a = calloc(1, sizeof(struct item) * kElements);

  /* Generate random number < 100 */
  for (i = 0; i < kElements; i++) {
    //sleep(0.1);
    if (i % 100 == 0) {
      printf("%c%c%c]",8,8,progress[(i/100) % 4]);
      fflush(stdout);
    }
    // p = &q[i];
    p = calloc(1, sizeof(struct item));
    p->p = random() %100;
    p->next = a;
    a = p;
  }
  printf("\n\nTiming...\n");
  for (i = 0; i < 100; i++) {
    clk = clock();
    sum = sumList(a);

    clk = clock();
    tot += clk;
    printf("List %ld ticks, sum %d\n", clk, sum);
  }
  printf("\nAverage time: %f ticks\n", ((double)tot)/100.0);
  getchar();
}
