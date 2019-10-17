/*
  Given a sorted list of integers, find all distinct pair of integers in the list of N integers with sum equal to a
  given number K with O (n log n ) or O(n) time complexity.
  Complete the function below which takes the array and K as parameters and return the number of pairs if any and 0 otherwise.
  
  Input Format
  First line of input will contain a positive integer T = number of test cases. Each test case will contain 2 lines. 
  First line of each test case two positive integer - N and K. Next line will contain N numbers separated by space
  in non-decreasing order.
  
  Output Format
  For each test case, print number of distinct pairs whose sum will be equal to k. A pair must have two numbers at
  different indices.Two pairs are different if at least one of the indices in them is uncommon.
  Indices - (2,3) and (3,2) are not distinct, but (2,3) and (2,4) are.

  Sample Input
  3
  10 11
  1 2 3 4 5 6 7 8 9 10
  5 10
  2 4 6 8 10
  6 27
  12 15 20 22 34 36
  
  Sample Output
  5
  2
  1
*/
int getPairsCount(int a[], int n, int sum)
{
  int i=0,j=n-1,c=0,i1,j1;
  while(i<j)
  {
    if(a[i]+a[j]==sum)
    {
      for(i1=i+1;a[i1-1]==a[i1]&&i1<j;i1++)
      {}
      for(j1=j-1;a[j1]==a[j1+1]&&j1>i+1;j1--)
      {}
      c=c+(i1-i)*(j-j1);
      i=i1;
      j=j1;
    }
    else if(a[i]+a[j]>sum)
    {
      j--;
    }
    else
    {
      i++;
    }
  }
  return c;
}
