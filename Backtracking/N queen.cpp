/*
  Given an integer n, return all distinct solutions to the n-queens puzzle.
  Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate
  a queen and an empty space respectively.
  For example,
  There exist two distinct solutions to the 4-queens puzzle:

  [
   [".Q..",  // Solution 1
    "...Q",
    "Q...",
    "..Q."],

   ["..Q.",  // Solution 2
    "Q...",
    "...Q",
    ".Q.."]
  ]
*/

int isSafe(int x,int y,vector<int> &v)
{
    for(int i=0;i<x;i++)
    {
        if(y==v[i] || abs(x-i)==abs(y-v[i]))
        {
            return 0;
        }
    }
    return 1;
}
void findCombinations(vector<vector<int>> &res,vector<int> &v,int rows,int index)
{
    if(index == rows)
    {
        res.push_back(v);
    }
    else
    {
        for(int i=0;i<rows;i++)
        {
            if(isSafe(index,i,v))
            {
                v[index] = i;
                findCombinations(res,v,rows,index+1);
            }
        }
    }
}
vector<vector<string>> Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string>> ans;
    vector<vector<int>> res;
    vector<int> v(A);
    // vector<vector<int>> pos;
    int index=0;
    int row_no=0;
    findCombinations(res,v,A,0);
    for(int i=0;i<res.size();i++)
    {
        vector<string> s;
        for(int j=0;j<A;j++)
        {
            string q(A,'.');
            q[res[i][j]] = 'Q';
            s.push_back(q);
        }
        ans.push_back(s);
    }
    return ans;
}
