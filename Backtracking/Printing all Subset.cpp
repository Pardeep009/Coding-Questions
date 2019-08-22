/*
  Given a set of distinct integers, S, return all possible subsets.

  Note:
  1.Elements in a subset must be in non-descending order.
  2.Also, the subsets should be sorted in ascending ( lexicographic ) order.
  3.The list is not necessarily sorted.
  Example :

  If S = [1,2,3], a solution is:

  [
    [],
    [1],
    [1, 2],
    [1, 2, 3],
    [1, 3],
    [2],
    [2, 3],
    [3],
  ]
  
*/
void findCombinations(vector<vector<int>> &res,vector<int> &v,int index,int start,vector<int> &A)
{
    vector<int> ans(v.begin(),v.begin()+index);
    res.push_back(ans);
    for(int i=start;i<A.size();i++)
    {
        v[index] = A[i];
        findCombinations(res,v,index+1,i+1,A);
    }
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> res;
    vector<int> v(A.size());
    sort(A.begin(),A.end());
    int index=0;
    int start=0;
    findCombinations(res,v,index,start,A);
    return res;
}
