/*

  Given A, B, C, find whether C is formed by the interleaving of A and B.

  Input Format:*
  The first argument of input contains a string, A.
  The second argument of input contains a string, B.
  The third argument of input contains a string, C.
  
  Output Format:
  Return an integer, 0 or 1:
      => 0 : False
      => 1 : True

  Examples:

  Input 1:
      A = "aabcc"
      B = "dbbca"
      C = "aadbbcbcac"
  Output 1:
      1
  Explanation 1:
      "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

  Input 2:
      A = "aabcc"
      B = "dbbca"
      C = "aadbbbaccc"
  Output 2:
      0
  Explanation 2:
      It is not possible to get C by interleaving A and B.
      
*/
int Solution::isInterleave(string A, string B, string C) {
    int i,j,k;
    int s1 = A.size();
    int s2 = B.size();
    int s3 = C.size();
    bool dp[s3+1][s1+1][s2+1];
    for(j=0;j<=s1;j++)
    {
        for(k=0;k<=s2;k++)
        {
            dp[0][j][k] = true;
        }
    }
    for(i=1;i<=s3;i++)
    {
        dp[i][0][0] = false;
    }
    bool x,y;
    for(i=1;i<=s3;i++)
    {
        for(j=0;j<=s1;j++)
        {
            for(k=0;k<=s2;k++)
            {
                x = false;
                y = false;
                if(j > 0 && A[j-1] == C[i-1])
                {
                    x = dp[i-1][j-1][k];
                }
                if(k > 0 && B[k-1] == C[i-1])
                {
                    y = dp[i-1][j][k-1];
                }
                dp[i][j][k] = x||y;
            }
        }
    }
    return dp[s3][s1][s2] == true ? 1 : 0;
 }
