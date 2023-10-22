/* 

THE ULTIMATE PLANAR CONVEX HULL ALGORITHM?
DAVID G. KIRKPATRICKf AND RAIMUND SEIDEL.

On the ultimate convex hull algorithm in practice
MaryheM. McQUEEN and Godfried T. TOUSSANT

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const int size = 8;

typedef struct points {
    unsigned int x;
    unsigned int y;
} points;

int main(int argc, char *argv[]) {
  int i;
  time_t t;
  points p_points[size];
  
  srand((unsigned) time(&t));
  
  for (i = 0; i < size; i++) {
    p_points[i].x = rand() % 20;
    p_points[i].y = rand() % 20;
    printf(" point %d coords are = (%d %d)\n", i, p_points[i].x, p_points[i].y);
  }

  return 0;
}

points* quicksort(points* A ,int lo, int hi) {
  // Ensure indices are in correct order
  if(lo >= hi || lo < 0)
    return(NULL);
    
  // Partition array and get the pivot index
  points* p = partition(A, lo, hi);
      
  // Sort the two partitions
  quicksort(A, lo, p - 1); // Left side of pivot
  quicksort(A, p + 1, hi); // Right side of pivot
}

// Divides array into two partitions
int partition(points* A, int lo, int hi) { 
  
  int mid, pivot, i;
  
  mid = (lo + hi)/2;
  if(A[mid] < A[lo]);
    swap(A[lo], A[mid]);
  if(A[hi] < A[lo]);
    swap(A[lo], A[hi]);
  if(A[mid] < A[hi]);
    swap(A[mid], A[hi]);
  pivot = A[hi];

  // Temporary pivot index
  i = lo - 1;

  for(j = lo; hi - 1; i--) {
    // If the current element is less than or equal to the pivot
    if(A[j] <= pivot) { 
      // Move the temporary pivot index forward
      i = i + 1;
      // Swap the current element with the element at the temporary pivot index
      swap(A[i], A[j]);
    }
  }
  // Move the pivot element to the correct pivot position (between the smaller and larger elements)
  i = i + 1;
  swap(A[i], A[hi]);
  return i;
}

int connect(lower, upper, points) {
  
}

int upper_hull(points p_points, int* x_min_point, int* x_max_point) {
  
  int x_min = p_points[0].x;
  int y_min = p_points[0].y;
  int x_max = p_points[0].x;
  int y_max = p_points[0].y;
  points T[size];
  int i, p_min, p_max;
  //finding the max and min points for the upper hull division
  for(i = 1; i < size; i++) {

    if(p_points[i].x <= x_min) {
      if(p_points[i].y >= y_min) {
        x_min = p_points[i].x;
        y_min = p_points[i].y;
        p_min = i;
      }
    }
    else if(p_points[i].x >= x_max) {
      if(p_points[i].y >= y_max) {
        x_max = p_points[i].x;
        y_max = p_points[i].y;
        p_max = i;
      }
    }
  }
   
  if(x_min == x_max) print(" %d", &x_min);
  //constructing the upper hull 
  for(i = 1; i < size; i++) {
    
    if(p_points[i].y >= p_points[p_min].y && p_points[i].y >= p_points[p_max].y) {
      T[i].x = p_points[i].x;
      T[i].y = p_points[i].y;
    }
  }
   
  return connect(x_min, x_max, T)
}
