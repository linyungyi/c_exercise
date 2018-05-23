#include <stdio.h>
#include <stdlib.h>

void selection_sort(int* src, int size)
{
  int tmp;
  int at;
  int min;
  
  for(int i; i<size-1; i++)
  {
      min = src[i];
      at = i;
      for(int j=i+1; j<size; j++)
      {
          if(min>src[j])
          {
              min = src[j];
              at = j;
          }
      }
      tmp = src[i];
      src[i] = min;
      src[at] = tmp;
  }
}

int main()
{
  int src_array[] = {8,2,5,7,4};
  int size =  sizeof(src_array)/sizeof(int);
  
  selection_sort(src_array, size);
  
  for(int i=0;i<size;i++)
    printf("%d ", src_array[i]);
  
  return 0;
  
}