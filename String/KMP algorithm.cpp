#include<bits/stdc++.h>
using namespace std;
int main()
{
    string txt="AABAACAADAABAABA";
    string path="AABA";
    int *infm = new int[path.length()+1];
    int j=0;
    for(int i=2;i<path.length()+1;i++)
    {
        if(path[i-1]==path[j])
        {
            infm[i] = infm[i-1]+1;
            j++;
        }
        else
        {
            j=0;
        }
    }
    j=-1;
    for(int i=0;i<txt.length();)
    {
        if(txt[i]==path[j+1])
        {
            j++;
            i++;
        }
        else
        {
            if(infm[j+1]==0)
            {
                j=-1;
                i++;
            }
            else
            {
                j=infm[j+1]-1;
            }
        }
        if(j==path.length()-1)
        {
            cout<<"starting at "<<i-path.length()<<endl;
            if(infm[j+1]==0)
            {
                j=-1;
            }
            else
            {
                j=infm[j+1]-1;
            }
        }
    }
}
