/*
  Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications. There are many options to multiply a chain of matrices because matrix multiplication is associative i.e. no matter how one parenthesize the product, the result will be the same.

  Example:
   if you had four matrices A, B, C, and D, you would have:

      (ABC)D = (AB)(CD) = A(BCD) = ....
  However, the order in which one parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency.

  For example:

  A: 10 × 30 matrix
  B : 30 × 5 matrix
  C : 5 × 60 matrix
  Then,
       (AB)C = (10×30×5) + (10×5×60) 
             = 1500 + 3000 
             = 4500 operations
       A(BC) = (30×5×60) + (10×30×60) 
             = 9000 + 18000 
             = 27000 operations.
  Given an array arr[] which represents the chain of matrices such that the ith matrix Ai is of dimension arr[i-1] x arr[i]. Your task is to write a function that should print the minimum number of multiplications needed to multiply the chain.

  Input: p[] = {40, 20, 30, 10, 30}   
  Output: 26000  
  There are 4 matrices of dimensions 40x20, 
  20x30, 30x10 and 10x30. Let the input 4 
  matrices be A, B, C and D.  The minimum 
  number of multiplications are obtained 
  by putting parenthesis in following way
  (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

  Input: p[] = {10, 20, 30, 40, 30} 
  Output: 30000 
  There are 4 matrices of dimensions 10x20, 
  20x30, 30x40 and 40x30. Let the input 4 
  matrices be A, B, C and D.  The minimum 
  number of multiplications are obtained by 
  putting parenthesis in following way
  ((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30
  
  Example:
  Input:
  2
  5
  1 2 3 4 5
  3
  3 3 3
  Output:
  38
  27
  
*/

#include <bits/stdc++.h>
using namespace std;
int MinCost(int arr[],int n)
{
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    int i,j,k;
    int mi;
    for(i=1;i<n-1;i++)
    {
        dp[2][i] = arr[i-1]*arr[i]*arr[i+1];
    }
    for(i=3;i<n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            mi = INT_MAX;
            int x,y;
            for(k=j;k<j+i-1;k++)
            {
                x = dp[k-j+1][j];
                y = dp[(j+i-1)-k][k+1];
                mi = min(mi,x+y+arr[j-1]*arr[k]*arr[j+i-1]);
            }
            dp[i][j] = mi;
        }
    }
    return dp[n-1][1];
}

int main() {
	//code
	int t,n,i;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    cout<<MinCost(a,n)<<endl;
	}
	return 0;
}
