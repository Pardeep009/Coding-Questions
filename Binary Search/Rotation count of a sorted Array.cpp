/*
` Given an array of integers, find the minimum number of rotations performed on some sorted array to create this given array.
  
  Input
  First line of input will contain a number T = number of test cases. Each test case will contain 2 lines. 
  First line will contain a number N = number of elements in the array (1 <= N <= 50).
  Next line will contain N space separated integers.
  Complete the function int rotationCount(int array[], int size) which will receive array and size of the array as 
  input and return how many times the sorted array is rotated. Function should return -1 if the array is not rotated.

  Output
  Print one line of output for each test case with the minimum number of rotations for given array.
  Sample Input:

  2
  6
  15 18 3 4 6 12
  6
  1 2 3 4 5 6
  
  Sample Output
  2
  -1

*/
int rotationCount(int a[], int size)
{
 	int l=0,r=size-1,mid,next,prev;
  if(a[l]<=a[r])
      return -1;
  while(l<=r)
  {
    mid = (l+r)/2;
    next = (mid+1)%size;
    prev = (mid-1)%size;
    if(a[mid]<=a[next]&&a[mid]<=a[prev])
      return mid;
    else if(a[mid]<=a[r])
      r=mid-1;
    else if(a[mid]>=a[l])
      l=mid+1;
  }

}
