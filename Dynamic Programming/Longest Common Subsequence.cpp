/*
  Given two sequences, find the length of longest subsequence present in both of them.
  Example:
  Input:
  2
  6 6
  ABCDGH
  AEDFHR
  3 2
  ABC
  AC

  Output:
  3
  2

  Explanation
  LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

  LCS of "ABC" and "AC" is "AC" of length 2
*/
#include <bits/stdc++.h>
using namespace std;
int maxLengthSubSequence(string s1,string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    int dp[l1+1][l2+1];
    memset(dp,0,sizeof(dp));
    int x,y;
    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                x = dp[i-1][j];
                y = dp[i][j-1];
                dp[i][j] = max(x,y);
            }
        }
    }
    return dp[l1][l2];
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
	    cout<<maxLengthSubSequence(s1,s2)<<endl;
	}
	return 0;
}
