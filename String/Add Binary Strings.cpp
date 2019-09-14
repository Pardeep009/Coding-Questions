/*
  Given two binary strings, return their sum (also a binary string).

  Example:

  a = "100"

  b = "11"
  Return a + b = “111”.
*/
string Solution::addBinary(string A, string B) {
    int carry = 0;
    int i=A.length()-1;
    int j=B.length()-1;
    string res = "";
    while(i>=0&&j>=0)
    {
        int c = A[i]-'0';
        int c1 = B[j]-'0';
        int sum = c + c1 + carry;
        res.push_back(sum%2+'0');
        carry = sum/2;
        i--;
        j--;
    }
    while(i>=0)
    {
        int c = A[i]-'0';
        int sum = c + carry;
        res.push_back(sum%2+'0');
        carry = sum/2;
        i--;
    }
    while(j>=0)
    {
        int c = B[j]-'0';
        int sum = c + carry;
        res.push_back(sum%2+'0');
        carry = sum/2;
        j--;
    }
    if(carry)
    res.push_back('1');
    reverse(res.begin(),res.end());
    return res;
}
