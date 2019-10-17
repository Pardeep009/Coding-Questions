/*

  There is an array of non-negative integers. A second array is formed by shuffling the elements of the first array and 
  deleting a random element. Given these two arrays, find which element is missing in the second array.

  Input
  First line of input will contain a positive integer T = number of test cases. Each test case will contain 3 lines.
  First line of each test case will contain two number m = size of the first array and n = size of the second array
  separated by space. Next 2 lines will contain m and n space separated non-negative integers.

  Output
  For each test case, print the missing element in the second array.
  
  Sample Input
  1
  5 4
  1 2 3 4 5
  3 4 1 2
  
  Sample Output
  5
  
*/
#include <stdio.h>
/* Include other headers as needed */
int main()
{
	int t,n,m;
  scanf("%d",&t);
  while(t-->0)
  {
    scanf("%d%d",&n,&m);
    int a[n],b[m];
    int i,j,sum=0,sum1=0
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
      sum=sum+a[i];
    }
    for(j=0;j<m;j++)
    {
      scanf("%d",&b[j]);
      sum1=sum1+b[j];
    }
    printf("%d\n",(sum-sum1));
  }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
