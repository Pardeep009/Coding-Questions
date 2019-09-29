/*
  You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in
  the knapsack. Note that we have only one quantity of each item.
  In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with
  N items respectively. Also given an integer W which represents knapsack capacity, 
  find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
  You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
  
  Example:
  
  Input:
  2
  3
  4
  1 2 3
  4 5 1
  2
  3
  1 2 3
  4 5 6
  Output:
  3
  1
  
*/
#include <bits/stdc++.h>
using namespace std;
int maxProfit(int profit[],int weight[],int n,int capacity)
{
    int i,j;
    int x,y;
    int dp[capacity+1][n+1];
    memset(dp,0,sizeof(dp));
    for(i=1;i<=capacity;i++)
    {
        for(j=1;j<=n;j++)
        {
            x = i-weight[j] >=0 ? profit[j] + dp[i-weight[j]][j-1] : 0 ;
            y = dp[i][j-1] ;
            dp[i][j] = max(x,y);
        }
    }
    return dp[capacity][n];
}

int main() {
	//code
	int t,n,capacity;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cin>>capacity;
	    int profit[n+1];
	    int weight[n+1];
	    for(int i=1;i<=n;i++)
	    {
	        cin>>profit[i];
	    }
	    for(int i=1;i<=n;i++)
	    {
	        cin>>weight[i];
	    }
	    cout<<maxProfit(profit,weight,n,capacity)<<endl;
	}
	return 0;
}
