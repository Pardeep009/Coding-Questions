/*
  Problem Link :-> https://leetcode.com/problems/longest-palindromic-subsequence/
  Given a string s, find the longest palindromic subsequence's length in s.

  Example 1:
  Input:
  "bbbab"
  Output:
  4
  One possible longest palindromic subsequence is "bbbb".
  
  Example 2:
  Input:

  "cbbd"
  Output:
  2
  One possible longest palindromic subsequence is "bb".
  
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int i,j;
        int size = s.size();
        int dp[size][size];
        memset(dp,0,sizeof(dp));
        for(i=0;i<size;i++)
            dp[i][i] = 1;
        for(i=size-2;i>=0;i--)
        {
            for(j=i+1;j<size;j++)
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][size-1];
    }
};
