/*
    Given a string of character, find the length of longest proper prefix which is also a proper suffix.
    Example:
    S = abab
    lps is 2 because, ab.. is prefix and ..ab is also a suffix.
    
    Example:
    Input:
    2
    abab
    aaaa

    Output:
    2
    3
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string path;
        cin>>path;
        // int *infm = new int[path.length()+1];
        int j=0;
        int ans = 0;                             // without using extra memory
        for(int i=2;i<path.length()+1;i++)
        {
            if(path[i-1]==path[j])
            {
                // infm[i] = j+1;
                ans = j+1;
                j++;
            }
            else
            {
                if(path[i-1]==path[0])
                {
                    // infm[i] = 1;
                    ans = 1;
                    j=1;
                }
                else
                {
                    // infm[i]=0;
                    ans = 0;
                    j=0;
                }
            }
        }
        cout<<ans<<endl;
        // cout<<infm[path.length()]<<endl;
    }
}
