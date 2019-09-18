/*

  Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
  Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

  Example :
  S = "ADOBECODEBANC"
  T = "ABC"
  Minimum window is "BANC"

  Note:
  If there is no such window in S that covers all characters in T, return the empty string ''.
  If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).
  
*/
string Solution::minWindow(string A, string B) {
    if(A.size()==0 || B.size()==0 || A.size()<B.size())
    return "";
    unordered_map<char,int> m;
    int i=0,j;
    while(i<B.size())
    {
        if(m.find(B[i])==m.end())
        {
            m[B[i]] = 1;
        }
        else
        {
            m[B[i]]++;   
        }
        // cout<<m[B[i]]<<" ";
        i++;
    }
    i=0;
    vector<int> v;
    while(i<A.size())
    {
        if(m.find(A[i])!=m.end())
        {
            v.push_back(i);
            // cout<<i<<" ";
        }
        i++;
    }
    int start = 0;
    if(v.size()&&B.size()==1)
    return B;
    int count = 0;
    int aend = -1;
    int astart = -1;
    int length = A.size();
    for(i=0;i<v.size();i++)
    {
        m[A[v[i]]]--;
        if(m[A[v[i]]]>=0)
        count++;
        if(count==B.size())
        {
            if(v[i]-v[start]<length)
            {
                length = v[i]-v[start];
                aend = v[i];
                astart = v[start];
            }
            count--;
            m[A[v[start]]]++;
            start++;
            while(m[A[v[start-1]]]<=0)
            {
                if(v[i]-v[start]<length)
                {
                    length = v[i]-v[start];
                    aend = v[i];
                    astart = v[start];
                }
                m[A[v[start]]]++;
                start++;
            }
        }
    }
    if(aend==-1)
    return "";
    string ans;
    while(astart<=aend)
    {
        ans.push_back(A[astart]);
        astart++;
    }
    return ans;
}
