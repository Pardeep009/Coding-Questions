/*

  Given a gold mine (M) of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold
  in tons. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) 
  that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down 
  towards the right. Your task is to find out maximum amount of gold which he can collect.
  
  Examples:

  Input : M[][] = {{1, 3, 3},
                   {2, 1, 4},
                   {0, 6, 4}};
  Output : 12 
  {(1,0)->(2,1)->(2,2)}

  Input: M[][] = {{1, 3, 1, 5},
                  {2, 2, 4, 1},
                  {5, 0, 2, 3},
                  {0, 6, 1, 2}};
  Output : 16
  (2,0) -> (1,1) -> (1,2) -> (0,3) OR
  (2,0) -> (3,1) -> (2,2) -> (2,3)
  
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t,r,c;
	cin>>t;
	while(t--)
	{
	    cin>>r>>c;
	    int a[r][c];
	    int mg = 0;
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    if(r==1)               // if there is one row,simply add all column values
	    {
	        for(int j=0;j<c;j++)
	        {
	            mg+=a[0][j];
	        }
	    }
	    else if(c==1)          // if there is one column,select maximum from all rows
	    {
	        for(int i=0;i<r;i++)
	        {
	            mg = max(mg,a[i][0]);
	        }
	    }
	    else
	    {
	        for(int j=1;j<c;j++)
    	    {
    	        for(int i=0;i<r;i++)
    	        {
    	            if(i==0)
    	            {
    	                a[i][j]+=max(a[i][j-1],a[i+1][j-1]);
    	            }
    	            else if(i==r-1)
    	            {
    	                a[i][j]+=max(a[i][j-1],a[i-1][j-1]);
    	            }
    	            else
    	            {
    	                a[i][j]+=max(max(a[i][j-1],a[i-1][j-1]),a[i+1][j-1]);    // find maximum from all directions reaching to it
    	            }
    	            mg = max(mg,a[i][j]);
    	        }
    	    }
	    }
	    cout<<mg<<endl;               // maximum gold collected
	}
	return 0;
}
