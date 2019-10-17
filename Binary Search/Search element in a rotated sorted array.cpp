/*
  
  Given an array of integers which is sorted but rotated by some number of times after sorting, and a integer k.
  Search the element k in this sorted rotated array efficiently. For example, suppose an array sorted in ascending order 
  is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

  Input
  First line of input will contain a number T = number of test cases. Each test case will contain 3 lines. 
  The first line will contain an integer k to be searched. Second line will contain a number N = number of elements
  in the array (1 <= N <= 50). Next line will contain N space separated integers.
  Complete the function int searchRotatedSortedArray(int *a, int size, int target) to search a value target
  in array a of size given, and if target found in the array return its index, otherwise return -1.
  You may assume no duplicate exists in the array.
  
  Output
  Print the index of k in given array for each test case in new line if found and print -1 if k is not present in given array.
  Sample Input:
  2
  3
  6
  15 18 2 3 6 12
  7
  7
  4 5 8 9 1 2 3
  
  Sample Output
  3
  -1
  
*/
  int searchRotatedSortedArray(int *a, int size, int x)
  {
    int l=0,r=size-1,mid;
      while(l<=r)
      { 
        mid = (l+r)/2;
        if(a[mid]==x)
          return mid;
        else if(a[mid]<=a[r])
        {
          if(x>a[mid]&&x<=a[r])
            l=mid+1;
          else
            r=mid-1;
        }
        else if(a[mid]>=a[l])
        {
          if(x>=a[l]&&x<a[mid])
            r=mid-1;
          else
            l=mid+1;
        }
      }
    return -1;
  }
