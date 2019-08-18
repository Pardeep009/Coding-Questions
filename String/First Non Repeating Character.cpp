/*
  Given a string S consisting of lowercase Latin Letters. Find the first non repeating character in S.
  Example:
  Input : 
  3
  5  
  hello
  12
  zxvczbtxyzvy
  6
  xxyyzz

  Output :
  h
  c
  -1
*/
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int i;
	    cin>>i;
	    string s;
	    cin>>s;
	    int h[26]={0};
	    for(i=0;i<s.length();i++)
	    {
	        h[s[i]-97]++;
	    }
	    for(i=0;i<s.length();i++)
	    {
	        if(h[s[i]-97]==1)
	        {
	            cout<<s[i]<<endl;
	            i=-1;
	            break;
	        }
	    }
	    if(i!=-1)
	    cout<<"-1"<<endl;
	}
	return 0;
}
