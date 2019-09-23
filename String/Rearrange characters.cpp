/*
  Given a string S with repeated characters (only lowercase). The task is to rearrange characters in a string such that no two 
  adjacent characters are same.

  Note : It may be assumed that the string has only lowercase English alphabets.

  Input:
  The first line of input contains an integer T denoting the number of test cases. 
  Then T test cases follow. Each test case contains a single line containing a string of lowercase english alphabets.

  Output:
  For each test case in a new line print "1" (without quotes) if the generated string doesn't contains any same adjacent
  characters, else if no such string is possible to be made print "0" (without quotes).
  Example:
  Input:
  3
  geeksforgeeks
  bbbabaaacd
  bbbbb

  Output:
  1
  1
  0

  Explanation:
  Testcase 1: All the repeated characters of the given string can be rearranged so that no adjacent characters in the string 
  is equal.
  Testcase 3: Repeated characters in the string cannot be rearranged such that there should not be any adjacent repeated
  character.
*/
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	string s;
	while(t--)
	{
	    cin>>s;
	    int h[26]={0};
	    int max = 0;
	    for(int i=0;i<s.length();i++)
	    {
	        h[s[i]-97]++;
	        max = max > h[s[i]-97] ? max : h[s[i]-97];
	    }
	    if(s.length()%2==0)
	    {
	        if(max > s.length()/2)
	        {
	            cout<<"0"<<endl;
	        }
	        else
	        {
	            cout<<"1"<<endl;
	        }
	    }
	    else
	    {
	        if(max - 1 > s.length()/2 )
	        {
	            cout<<"0"<<endl;
	        }
	        else
	        {
	            cout<<"1"<<endl;
	        }
	    }
	}
	return 0;
}
