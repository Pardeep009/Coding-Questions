/*
  HammingDistance(2, 7) = 2, as only the first and the third bit differs in the binary representation of 2 (010) and 7 (111).
  Given an array of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array.
  Return the answer modulo 1000000007.
  
  Example
  Let f(x, y) be the hamming distance defined above.
  A=[2, 4, 6]
  We return,
  f(2, 2) + f(2, 4) + f(2, 6) + 
  f(4, 2) + f(4, 4) + f(4, 6) +
  f(6, 2) + f(6, 4) + f(6, 6) = 

  0 + 2 + 1
  2 + 0 + 1
  1 + 1 + 0 = 8
*/
int Solution::hammingDistance(const vector<int> &A) {
    long long c=0;
    long long total=0;
    for(int i=0;i<32;i++)
    {
        c = 0;
        int num = 1<<i;
        for(int j=0;j<A.size();j++)
        {
            if(num&A[j])
            {
                c++;
            }
        }
        total+=(c*(A.size()-c))*2;
    }
    return total%1000000007;
}
