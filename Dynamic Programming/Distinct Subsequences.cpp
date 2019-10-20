/*
  Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to
  the sequence B.

  Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting
  some (can be none) of the characters without disturbing the relative positions of the remaining characters. 
  (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

  Input Format:
  The first argument of input contains a string, A.
  The second argument of input contains a string, B.
  
  Output Format:
  Return an integer representing the answer as described in the problem statement.
  
  Constraints:
  1 <= length(A), length(B) <= 700
  
  Example :
  Input 1:
      A = "abc"
      B = "abc"

  Output 1:
      1

  Explanation 1:
      Both the strings are equal.
      
  Input 2:
      A = "rabbbit" 
      B = "rabbit"
      
  Output 2:
      3

  Explanation 2:
      These are the possible removals of characters:
          => A = "ra_bbit" 
          => A = "rab_bit" 
          => A = "rabb_it"

      Note: "_" marks the removed character.
*/
int Solution::numDistinct(string A, string B) {
    int m = A.size();
    int n = B.size();
    int dp[n+1][m+1];
    int i,j;
    for(i=0;i<=m;i++)
    {
        dp[0][i] = 1;
    }
    for(i=1;i<=n;i++)
    {
        dp[i][0] = 0;
    }                                       
    for(i=1;i<=n;i++)                  
    {                                 
        for(j=1;j<=m;j++)          
        {                          
            if(B[i-1] == A[j-1])   
            {                     
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1]; // ways of making remaining string in two strings +  
                                                      // ways of making same string B with removal of just one character from A string.
            }
            else
            {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[n][m];
}
