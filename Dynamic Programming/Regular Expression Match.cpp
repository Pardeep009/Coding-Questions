/*
  Implement wildcard pattern matching with support for ‘?’ and ‘*’ for strings A and B.

  ’?’ : Matches any single character.
  ‘*’ : Matches any sequence of characters (including the empty sequence).
  The matching should cover the entire input string (not partial).

  Input Format:
  The first argument of input contains a string A.
  The second argument of input contains a string B.
  
  Output Format:
  Return 0 or 1:
      => 0 : If the patterns do not match.
      => 1 : If the patterns match.
  
  Examples :
  
  Input 1:
      A = "aa"
      B = "a"
      
  Output 1:
      0

  Input 2:
      A = "aa"
      B = "aa"

  Output 2:
      1

  Input 3:
      A = "aaa"
      B = "aa"

  Output 3:
      0

  Input 4:
      A = "aa"
      B = "*"

  Output 4:
      1

  Input 5:
      A = "aa"
      B = "a*"

  Output 5:
      1

  Input 6:
      A = "ab"
      B = "?*"

  Output 6:
      1

  Input 7:
      A = "aab"
      B = "c*a*b"

  Output 7:
      0

*/
int Solution::isMatch(const string A, const string B) {
    int asize = A.size();
    int bsize = B.size();
    int dp[bsize+1][asize+1];
    memset(dp,0,sizeof(dp));
    int i,j,k;
    dp[0][0] = 1;
    if(B[0] == '*')
    {
        for(i=0;i<=asize;i++)
        {
            dp[0][i] = 1;
        }
    }
    for(i=1 ; i<=bsize && B[i-1] == '*' ; i++)
    {
        dp[i][0] = 1;
    }
    for(i=1;i<=bsize;i++)
    {
        for(j=1;j<=asize;j++)
        {
            if(B[i-1] == '*')
            {
                dp[i][j] = 0;
                for(k=j;k>=0;k--)
                {
                    if(dp[i-1][k])
                    {
                        dp[i][j] = 1;
                        break;
                    }
                }
            }
            else if(B[i-1] == '?')
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                if(A[j-1] == B[i-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
    }
    return dp[bsize][asize];
}
