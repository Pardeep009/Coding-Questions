/*
  Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

  Example:
  Given [100, 4, 200, 1, 3, 2],
  The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

  Your algorithm should run in O(n) complexity.
*/
int Solution::longestConsecutive(const vector<int> &A) {
    map<int,int> m;
    int i=0;
    int size = A.size();
    while(i<size)
    {
        m[A[i]] = 1;
        i++;
    }   
    auto it = m.begin();
    int prev = it->first;
    it++;
    int len = 1;
    int max_len = 1;
    for(;it!=m.end();it++)
    {
        if(it->first-prev == 1)
        {
           len++; 
        }
        else
        {
            max_len = max_len > len ? max_len : len;
            len=1;
        }
        prev = it->first;
    }
    max_len = max_len > len ? max_len : len;
    return max_len;
}
