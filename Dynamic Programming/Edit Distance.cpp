/*
  Given two strings str1 and str2 and below operations that can performed on str1. 
  Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.
  1. Insert
  2. Remove
  3. Replace
  All of the above operations are of cost=1.
  Example:
  Input:
  1
  4 5
  geek gesek

  Output:
  1

  Explanation:
  Testcase 1: One operation is required to make 2 strings same i.e. removing 's' from str2.
*/
#include <iostream>
using namespace std;
int minEditDistance(string s1,string s2,int n,int m)
{
    int i,j;
    int dp[n+1][m+1];
    
    for(i=0;i<=m;i++)
    dp[0][i] = i;
    
    for(i=0;i<=n;i++)
    dp[i][0] = i;
    
    int x,y,z;
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                x = 1 + min(dp[i][j-1],dp[i-1][j]);
                y = 1 + min(dp[i-1][j],dp[i][j-1]);
                z = 1 + dp[i-1][j-1];
                dp[i][j] = min(min(x,y),z);
            }
        }
    }
    return dp[n][m];
    
}
int main() {
	//code
	int t,n,m;
	string s1,s2;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    cin>>s1>>s2;
	    cout<<minEditDistance(s1,s2,n,m)<<endl;
	}
	return 0;
}
