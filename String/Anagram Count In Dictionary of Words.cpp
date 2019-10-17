/*
  Print No of Anagram Strings
  For example ,String are
  abc
  cba
  bca
  sdf
  fds
  dfs
  
  No of Anagram Strings are 6

*/

#include <bits/stdc++.h>
using namespace std;

void printAnagramsCount(vector<string> &v)
{
    int i;
    int size = v.size();
    for(i=0;i<size;i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    sort(v.begin(),v.end());
    int count = 0;
    i=0;
    int j;
    while(i<size)
    {
        j = i+1;
        while(j<size && v[i] == v[j])
        {
            count+= j - i;
            j++;
        }
        i = j;
    }
    cout<<count<<endl;
}

int main()
{
    string s;
    vector<string> v;
    cout<<"Enter Words,Press -1 for end"<<endl;
    cin>>s;
    while(s!="-1")
    {
        v.push_back(s);
        cin>>s;
    }
    printAnagramsCount(v);
}
