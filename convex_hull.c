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

typedef struct bridge_points {
    unsigned int pix;
    unsigned int piy;
    unsigned int pjx;
    unsigned int pjy;
} bridge_points;

int main(int argc, char *argv[]) {
  int i, lo, hi;
  time_t t;
  points p_points[size];
  lo = 0;
  hi = size-1;
  
  srand((unsigned) time(&t));
  
  for (i = 0; i < size; i++) {
    p_points[i].x = rand() % 20;
    p_points[i].y = rand() % 20;
    printf(" point %d coords are = (%d %d)\n", i, p_points[i].x, p_points[i].y);
  }
   
  quicksort(p_points, lo, hi);

  return 0;
}

void quicksort(points *A ,int lo, int hi) {
  // Ensure indices are in correct order
  if(lo >= hi || lo < 0) {
    print("Indexes error");
    exit(1);
  }
  
  // Partition array and get the pivot index
  int p = partition(A, lo, hi);
      
  // Sort the two partitions
  quicksort(A, lo, p - 1); // Left side of pivot
  quicksort(A, p + 1, hi); // Right side of pivot
}

// Simple selection of pivot
int selection(lo, hi) {
    int mid = (lo + hi)/2;
    return(mid);
}

void swap(points *A, int a, int b){
   int temp = *A[a];
   *A[a] = *A[b];
   *A[b] = temp;
}

// Divides array into two partitions
int partition(points *A, int lo, int hi) { 
  int mid, pivot, i; 
  mid = selection(lo, hi);

  if(A[mid].x < A[lo].x)
    swap(A, lo, mid);
  if(A[hi].x < A[lo].x)
    swap(A, lo, hi);
  if(A[mid].x < A[hi].x)
    swap(A, mid, hi);

  // Temporary pivot index
  i = lo - 1;

  for(j = lo; hi - 1; i--) {
    // If the current element is less than or equal to the pivot
    if(A[j] <= pivot) { 
      // Move the temporary pivot index forward
      i = i + 1;
      // Swap the current element with the element at the temporary pivot index
      swap(A, i, j);
    }
  }
  // Move the pivot element to the correct pivot position (between the smaller and larger elements)
  i = i + 1;
  swap(A, i, hi);
  return i;
}

int median(points *A, int lo, int hi) {
    //range of array A
    int A_range = hi - lo + 1;
    if(A_range%2==0) {
      return((A[A_range/2] + A[A_range/2-1])/2);
    } 
    else {
      return A[A_range/2];
    } 
}

bridge_points bridge(points *T, int size_s, int a, bridge_points *b_p) {
    bridge_points b_p[size_s]; 
    //|S|=2 then ((i,j)), S = {pi, pj}, x(pi) < x(pj)
     if(size_s == 2) {
        b_p.pix = T[0].x;
        b_p.piy = T[0].y;
        b_p.pjx = T[1].x;
        b_p.pjy = T[1].y;
        return(b_p);
    }
    return(bridge(candidates, a));
}

int connect(int lo, int hi, int size_s, points *T) {
  int a = median(T, lo, hi);
  points Sl[size_s], Sr[size_s]; //Sl and Sr will have max size size_s
  int n_sl = 0; 
  int n_sr = 0; //Sl and Sr # of points for static arrays
  bridge_points *b_p;

  bridge(T, size_s, a, b_p);

  for(i = 0; i < size_s; i++) {
    if(T[i].x <= b_p.pix) {
      Sl[i].x = b_p.pix;
      Sl[i].y = b_p.piy;
      n_sl++;
    }
  }
  
  for(i = 0; i < size_s; i++) {
   if(T.y >= b_p.pjx) {
     Sr[i].x = b_p.pjx;
     Sr[i].y = b_p.pjy;
     n_sr++;
   }
  }
  
  if(b_p.pix == lo) {
    print(" %d", &lo);
  } else {
    connect(lo, b_p.pix, n_sl, Sl);
  }
  if(b_p.pjx == hi) {
    print(" %d", &hi);
  } else {
    connect(b_p.pjx, hi, n_sr, Sr);
  }
}

int upper_hull(points *p_points, int lo, int hi) {
  
  points T[size];
   
  if(p_points[lo].x == p_points[hi].x) {
    print(" %d", p_points[lo]);
    exit(1);
  }
  //constructing the upper hull 
  for(i = 0; i < size; i++) {
    
    if(p_points[i].y >= p_points[lo].y && p_points[i].y >= p_points[hi].y) {
      T[i].x = p_points[i].x;
      T[i].y = p_points[i].y;
    }
  }
   
  return connect(lo, hi, size, T);
}
