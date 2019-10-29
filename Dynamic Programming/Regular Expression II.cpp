/*
  Problem Link :-> https://www.interviewbit.com/problems/regular-expression-ii/
  Implement regular expression matching with support for '.' and '*'.

  '.' Matches any single character.
  '*' Matches zero or more of the preceding element.

  The matching should cover the entire input string (not partial).
  
  Some examples:
  
  isMatch("aa","a") → 0
  isMatch("aa","aa") → 1
  isMatch("aaa","aa") → 0
  isMatch("aa", "a*") → 1
  isMatch("aa", ".*") → 1
  isMatch("ab", ".*") → 1
  isMatch("aab", "c*a*b") → 1
  Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/
int Solution::isMatch(const string A, const string B) {
    int i,j;
    int asize = A.size();
    int bsize = B.size();
    bool dp[bsize+1][asize+1];
    memset(dp,false,sizeof(dp));
    dp[0][0] = true;
    for(i=1;i<=bsize;i++)
    {
        if(B[i-1] == '*')
        {
            dp[i][0] = dp[i-2][0];
        }
    }
    for(i=1;i<=bsize;i++)
    {
        for(j=1;j<=asize;j++)
        {
            if(B[i-1] == '*')
            {
                if(dp[i-2][j])            // if previous character dosen't come single time
                {
                    dp[i][j] = true;
                }
                else if(B[i-2] == '.' || B[i-2] == A[j-1])            // if previous character is . OR same
                {
                    dp[i][j] = dp[i][j-1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            else if(B[i-1] == '.' || B[i-1]==A[j-1])        // if previous character is . OR same
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[bsize][asize];
}

