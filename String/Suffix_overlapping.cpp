/*
Longest Common Substring with overlapping
*/
#include<bits/stdc++.h>
using namespace std;


bool comparator(char *a,char *b)
{
    return strcmp(a,b) > 0 ? 1 : 0 ;
}

int main()
{
    int i=0,k=0;
    string str;
    cout<<"Enter String"<<endl;
    getline(cin,str);
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    int len = str.length();
    char ch[len];
    strcpy(ch,str.c_str());    
    char *ptr[len];
    for(i=0;i<len;i++)
    {
        ptr[i] = &ch[i];
    }
    char *temp;
    sort(ptr,ptr+len,comparator);
    int ma = 0;
    int c = 0;
    int j;
    string ans = "";
    for(i=0;i<len-1;i++)
    {
        c=0;
        k=0;
        j=i+1;
        while((*(ptr+i)+k) && (*(ptr+j)+k) && *(*(ptr+i)+k) == *(*(ptr+j)+k))
        {
            cout<<*(*(ptr+i)+k);
            c++;
            k++;
        }
        cout<<endl;
        if(c>ma)
        {
            j=0;
            ans = "";
            while(j<k)
            {
                ans = ans + *(*(ptr+i)+j);
                j++;
            }
        }
        ma = max(c,ma);
    }
    cout<<endl<<ma;
    cout<<endl<<ans;
}
