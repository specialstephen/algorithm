/*
 * key idea: Divide-and-conquer algorithm.
 *           Sorts "in place".
 * Pseudocode for quicksort
 * Quicksort(A,p,r)
 *    if p < r
 *         then q <- Partition(A,p,r)
 *          Quicksort(A,p,q-1)
 *          Quicksort(A,q+1,r)
 *
 * Initial call: Quicksort(A,1,n)
*/
#include<stdio.h>

// swap two integers 
void swap(int *m, int *n)
{
  int temp;
  temp = *m;
  *m = *n;
  *n = temp;
}
/* Partition the array into two subarrays around a pivot,such that elements in lower subawway <= pivot <= elements in upper subarray */
int partition(int *a, int m, int n)
{
  int pivot = a[m];
  int i = m;
  for(int j = m + 1; j <= n; j++)
  {
    if (a[j] <= pivot)
    {
      i++;
      swap(&a[i],&a[j]);
     }
  }
  swap(&a[m],&a[i]); // swap pivot and a[i]
  return i;        // return founded index of pivot
}
// recurrence quicksort the subarray
void quicksort(int *a, int p, int r)
{
  if (p < r)
  {
    int q = partition(a, p, r);
    quicksort(a, p, q-1);
    quicksort(a, q+1,r);
  }
}

int main(int argc, char* argv[])
{
  int a[8] = {6,10,13,5,8,3,2,11};
  quicksort(a,0,7);
  for(int i=0;i < 8 ;i++)
  {
    printf("%d ", a[i]);
  }
  return 0;
}
