/*
  Given a string s, partition s such that every string of the partition is a palindrome.

  Return all possible palindrome partitioning of s.

  For example, given s = "aab",
  Return

    [
      ["a","a","b"]
      ["aa","b"],
    ]
    
*/

vector<vector<string>> res;

int isPal(string A,int start,int end)
{
    while(start<end)
    {
        if(A[start]!=A[end])
        return 0;
        start++;
        end--;
    }
    return 1;
}

void findCombinations(string A,int start,vector<string> &ans)
{
    if(start == A.size())
    {
        res.push_back(ans);
    }
    else
    {
        string s="";
        for(int i=start;i<A.size();i++)
        {
            s = s + A[i];
            if(isPal(A,start,i))
            {
                ans.push_back(s);
                findCombinations(A,i+1,ans);
                ans.pop_back();
            }
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    res.clear();
    vector<string> ans;
    findCombinations(A,0,ans);
    return res;
}
