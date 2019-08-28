/*
  
  Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
  The same repeated number may be chosen from C unlimited number of times.

  Note:
  All numbers (including target) will be positive integers.
  Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
  The combinations themselves must be sorted in ascending order.
  CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
  The solution set must not contain duplicate combinations.
  Example, 
  Given candidate set 2,3,6,7 and target 7,
  A solution set is:
  [2, 2, 3]
  [7]
  
*/
vector<vector<int>> res;
int findCombinations(vector<int> &A,int sum,vector<int> &v,int index,int i)
{
    if(sum<0||i>=A.size())
    {
        return 0;
    }
    else if(sum==0)
    {
        vector<int> v1(v.begin(),v.begin()+index);
        res.push_back(v1);
        return 1;
    }
    else
    {
        for(int j=i;j<A.size();j++)
        {
            v[index] = A[j];
            findCombinations(A,sum-A[j],v,index+1,j);
        }
    }
}
vector<vector<int>> Solution::combinationSum(vector<int> &A, int B) {
    res.clear();
    sort(A.begin(),A.end());
    int i=0;
    int index=0;
    vector<int> a;
    for(i=0;i<A.size();i++)
    {
        if(i==0||A[i]!=A[i-1])
        a.push_back(A[i]);
    }
    i=0;
    int size = B/a[0]+1;
    vector<int> v(size);
    findCombinations(a,B,v,index,i);
    return res;
}
