/*
 * running time is O(n\lg n),"in place sorts"
 * define the height of a node in a heap to be the number of edges on the longest
 * simple downward path from the node to a leaf,and we define the height of the heap 
 * to be the height of its root. n elements height is \Theta(\lg n).
 * MAX-HEAPIFY procedure: maintaining the max-heap property.O(\lg n)
 * BUILD-MAX-HEAP procedure: produce a max-heap form an unsorted input array.
 * HEAPSORT procedure: sorts an array in place. O(n\lg n)
 *
 * MAX-HEAPIFY assume that the binary trees rooted at LEFT(i) and RIGHT(i) are 
 * max-heap, but that A[i] might be smaller than its children.
 * MAX-HEAPIFY(A,i)
 * l = LEFT(i)
 * r = RIGHT(i)
 * if l <= A.heap-size and A[l] > A[i]
 *    largest = l
 * else largest = i
 * if r <= A.heap-size and A[r] > A[largest]
 *    largest = r
 * if largest != i 
 *    exchange A[i] with A[largest]
 *    MAX-HEAPIFY(A,largest)    // subtree rooted at largest might violate the 
 *                             // max-heap property.
 *
 * Building a heap
 * bottom-up manner
 * the elements in the subtree A[(floor(n/2)+1) .. n] are all leaves of the tree.
 * BUILD-MAX-HEAP(A)
 * A.heap-size = A.length
 * for i = floor(A.length/2) downto 1
 *    MAX-HEAPIFY(A,i)
 *
 * HEAPSORT(A)
 * BUILD-MAX-HEAP(A)
 * for i = A.length downto 2
 *    exchange A[1] with A[i]
 *    A.heap-size = A.heap-size -1
 *    MAX-HEAPIFY(A,1)
*/

#include<stdio.h>

#define ARRAY_SIZE  6
  
void shiftDown(int numbers[], int root, int heap_size)
{
  int largest,temp;
  if ((root*2 <= heap_size) && (numbers[root*2] > numbers[root]))
    largest = root * 2;
  else largest = root;
  if ((root*2 + 1 <= heap_size) && (numbers[root*2 + 1] > numbers[largest]))
    largest = root * 2 + 1;
  if (largest != root)
  {
    temp = numbers[root];
    numbers[root] = numbers[largest];
    numbers[largest] = temp;
    shiftDown(numbers,largest,heap_size);
  }
}
void heapSort(int numbers[], int array_size)
{
  int i, temp;
  /* 自底向上构造最大堆*/
  for (i = (array_size / 2) - 1; i >= 0; i--)
    shiftDown(numbers, i, array_size);
  
  for (i = array_size-1; i >= 1; i--)
  {
    temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    shiftDown(numbers, 0, i-1);
  }
}

int main(int argc, char *argv[])
{
  int a[ARRAY_SIZE] = {2,4,5,1,8,7};
  heapSort(a,ARRAY_SIZE);
  int j;
  for (j = 0; j < ARRAY_SIZE; j++)
    printf("%d ", a[j]);

  return 0;
}
