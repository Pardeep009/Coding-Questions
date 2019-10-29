/*

  Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')',
  find out the length of the longest valid substring.
  NOTE: Length of smallest the valid substring ( ) is 2.
  
  Examples 

  Input
  4
  (()(
  ()()((
  ((()()())))
  ()(())(

  Output
  2
  4
  10
  6
  
*/
#include <bits/stdc++.h>
using namespace std;

int maxValidLengthSubstring(string s)
{
    int maxlen = 0;
    int len = 0;
    stack<int> s1;
    // stack<int> s2;
    s1.push(-1);
    int size = s.size();
    int i=0;
    while(i<size)
    {
        if(s[i] == '(')
        {
            s1.push(i);
        }
        else
        {
            s1.pop();
            if(s1.size())
            {
                len = i - s1.top();
                maxlen = max(maxlen,len);
            }
            else
            {
                s1.push(i);
            }
        }
        i++;
    }
    return maxlen;
}

int main() {
	//code
	int t;
	cin>>t;
	string s;
	while(t--)
	{
	    cin>>s;
	    cout<<maxValidLengthSubstring(s)<<endl;
	}
	return 0;
}
