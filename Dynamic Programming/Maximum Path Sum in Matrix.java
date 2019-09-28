/*
  Given a N X N  matrix Matrix[N][N] of positive integers.  There are only three possible moves from a cell Matrix[r][c].

  1. Matrix[r+1][c]

  2. Matrix[r+1][c-1]

  3. Matrix[r+1][c+1]

  Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.
  
  Example:
  Input:
  1
  2
  348 391 618 193

  Output:
  1009

  Explanation: In the sample test case, the path leading to maximum possible sum is 391->618.  (391 + 618 = 1009)
  
*/
/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static int maxPathMatrix(int a[][],int n)
    {
        // int n = a.length();
        int max_path_sum = 0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    a[i][j] = a[i][j] + Math.max(a[i-1][j+1],a[i-1][j]);
                }
                else if(j==n-1)
                {
                    a[i][j] = a[i][j] + Math.max(a[i-1][j-1],a[i-1][j]);
                }
                else
                {
                    a[i][j] = a[i][j] + Math.max(Math.max(a[i-1][j-1],a[i-1][j]),a[i-1][j+1]);
                }
                max_path_sum = Math.max(max_path_sum,a[i][j]);
            }
        }
        return max_path_sum;
    }
    
	public static void main (String[] args) {
		//code
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int n;
		while(t!=0)
		{
		    t--;
		    n = sc.nextInt();
		    int [][]a= new int[n][n];
		    for(int i=0;i<n;i++)
		    {
		        for(int j=0;j<n;j++)
		        {
		            a[i][j] = sc.nextInt();
		        }
		    }
		    System.out.println(maxPathMatrix(a,n));
		}
		
	}
}
