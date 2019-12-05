#include<bits/stdc++.h>
using namespace std;
int main()
{
    string txt = "AABAACAADAABAABA";
    string path = "AABA";
    int size1 = txt.size();
    int size2 = path.size();
    if(size1 == 0 || size2 == 0)
    {
        cout<<"error : one of the string is empty"<<endl;
    }
    int ans = -1;
    vector<int> infm(size2,0);
    int j=0,i;
    for(i=1;i<size2;i++)
    {
        if(path[i] == path[j])
        {
            infm[i] = infm[i-1]+1;
            j++;
        }
        else {
            j=0;
        }
    }
    j=0;
    for(i=0;i<size1;)
    {
        if(txt[i] == path[j])
        {
            i++;
            j++;
        }
        else 
        {
            if(j==0)
            {
                i++;
            }
            else {
                j = infm[j-1];
            }
        }
        if(j == size2)
        {
            ans = i - size2;
            j = infm[j-1];
            cout<<"starting at "<<ans<<endl;
        }
    }
    if(ans == -1)
    {
        cout<<"No Match Found"<<endl;
    }
}
