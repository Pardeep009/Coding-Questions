/*

  Given n dice each with m faces, numbered from 1 to m, find the number of ways to get sum X.
  X is the summation of values on each face when all the dice are thrown.
  
  Example:
  Input: 
  2
  6 3 12
  10 8 25

  Output:
  25
  318648
  
*/

#include <bits/stdc++.h>
using namespace std;
long long GetPossibleWays(int faces,int dice,int sum)
{
    int i,j,k;
    long long dp[sum+1][dice+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(i=1;i<=sum;i++)
    {
        for(j=1;j<=dice;j++)
        {
            for(k=1;k<=faces;k++)
            {
                if(k<=i)
                {
                    dp[i][j] += dp[i-k][j-1];
                }
                else
                {
                    break;
                }
            }
        }
    }
    return dp[sum][dice];
}

int main() {
	//code
	int t;
	cin>>t;
	int faces,dice,sum;
	while(t--)
	{
	    cin>>faces;
	    cin>>dice;
	    cin>>sum;
	    cout<<GetPossibleWays(faces,dice,sum)<<endl;
	}
	return 0;
}
