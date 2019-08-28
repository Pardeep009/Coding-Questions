/*
  Given a digit string, return all possible letter combinations that the number could represent.
  
  A mapping of digit to letters (just like on the telephone buttons) is given below.
  
  http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png
  
  The digit 0 maps to 0 itself.
  The digit 1 maps to 1 itself.

  Input: Digit string "23"
  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
  Make sure the returned strings are lexicographically sorted.
*/
string letters(char ch)
{
    switch(ch)
    {
        case '0':
        return "0";
        
        case '1':
        return "1";
        
        case '2':
        return "abc";
        
        case '3':
        return "def";
        
        case '4':
        return "ghi";
        
        case '5':
        return "jkl";
        
        case '6':
        return "mno";
        
        case '7':
        return "pqrs";
        
        case '8':
        return "tuv";
        
        case '9':
        return "wxyz";
    }
}
void findCombinations(vector<string> &ans,vector<string> &all,int index,string s)
{
    if(index==all.size())
    {
        ans.push_back(s);
    }
    else
    {
        for(int i=0;i<all[index].size();i++)
        {
            s.push_back(all[index][i]);
            findCombinations(ans,all,index+1,s);
            s.pop_back();
        }
    }
}
vector<string> Solution::letterCombinations(string A) {          // called from main
    vector<string> all;
    string s;
    int i=0;
    for(i=0;i<A.length();i++)
    {
        all.push_back(letters(A[i]));
    }
    i=0;
    vector<string> ans;
    findCombinations(ans,all,i,s);
    return ans;
}
