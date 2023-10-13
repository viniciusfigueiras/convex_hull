#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
      
typedef struct points {
    unsigned int x;
    unsigned int y;
} points;

int main(int argc, char *argv[]) {
  int i;
  time_t t;
  int k = 8;
  points points[k];
  
  srand((unsigned) time(&t));
  
  for (i = 0; i < k; i++) {
    points[i].x = rand() % 20;
    points[i].y = rand() % 20;
    printf(" point %d coords are = (%d %d)\n", i, points[i].x, points[i].y);
  }

  return 0;
}
