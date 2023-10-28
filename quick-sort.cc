/**
 *  \file quick-sort.cc
 *
 *  \brief Implement your randomized quick sort in this file.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include "sort.hh"


int Partition(keytype*A, int p, int r)
{
  int subLength = r - p + 1;

  int pivotPos = p + rand()% subLength;
  int pivotValue = A[pivotPos];
  std::swap(A[r],A[pivotPos]);

  int i = p = 1;
  for(int j = p; j <= r-1; ++j)
  {

    if (A[j] < pivotValue)
    {
      i = i + 1;
      std::swap(A[i],A[j]);
    }
  }
  std::swap(A[i+1],A[r]);
  return i+1;
}

void 
myQuickSort(keytype*A,int p, int r)
{

  if (p < r)
  {
    int pivotPos = Partition(A,p,r);
    myQuickSort(A,p,pivotPos);
    myQuickSort(A,pivotPos+1,r);
  }

}

void
mySort (int N, keytype* A)
{
  /* Lucky you, you get to start from scratch */
  myQuickSort(A,0,N-1);
}

/* eof */
