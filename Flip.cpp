/*
  Problem Link :-> https://www.interviewbit.com/problems/flip/
  You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN.
  In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR.
  By flipping, we mean change character 0 to 1 and vice-versa.

  Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. 
  If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements
  denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

  Notes:
  Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
  
  For example,
  S = 010
  Pair of [L, R] | Final string
  _______________|_____________
  [1 1]          | 110
  [1 2]          | 100
  [1 3]          | 101
  [2 2]          | 000
  [2 3]          | 001
  We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
  Another example,

  If S = 111
  No operation can give us more than three 1s in final string. So, we return empty array [].

*/
vector<int> Solution::flip(string A) {
    int i=0;
    int size = A.size();
    int l=size+1,r=size+1;
    int s=0,e=0;
    int sum = 0;
    int maxsum=0;
    int f=1;
    while(i<size)
    {
        sum += A[i] == '0' ? 1 : -1;
        if(sum>maxsum)
        {
            if(f==1)
            {
                l = s;
                f=0;
            }
            r = i;
            maxsum = sum;
        }
        if(sum<0)
        {
            sum = 0;
            f=1;
            s= i+1;
        }
        i++;
    }
    if(l==size+1)
    return vector<int>{};
    return vector<int>{l+1,r+1};
}
