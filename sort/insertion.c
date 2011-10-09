/* 
 * an incremental algorithm
 * Insertion_Sort(A):
 * for j <- 2 to length[A]
 * Do key <- A[j]
 *    // put A[j] into the sorted sequence A[1 .. j-1]
 *    i = j-1
 *   while i > 0 and A[i] > key
 *         DO A[i+1] <- A[i]
 *              i <- i - 1
 *  A[i+1] <- key
*/
#include<stdio.h>

#define ARRAY_SIZE 6

void insertionSort(int numbers[], int array_size)
{
  int i, j, index;
  
  for (i = 1; i < array_size; i++)
  {
    index = numbers[i];
    j = i;
    while((j > 0) && (numbers[j-1]>index))
    {
      numbers[j] = numbers[j-1];
      j = j - 1;
    }
    numbers[j] = index;
  }
}

int main(int argc, char *argv[])
{
  int a[ARRAY_SIZE] = {2,7,4,9,6,8};
  int i;
  insertionSort(a,ARRAY_SIZE);
  for(i=0; i < ARRAY_SIZE; i++)
  {
    printf("%d ", a[i]);
  }
}
