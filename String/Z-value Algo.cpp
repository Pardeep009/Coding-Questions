#include<stdio.h>
#include<string.h>
int len;
char* z_value(char *str)
{
    int l=1,r=1,i;
    printf("%s",str);
    int z[strlen(str)];
    for(i=1;i<strlen(str);i++)
    {
        if(i>=r)
        {
            l=i;
            r=i;
            while((str[r]==str[r-l])&&((r-l)<len))
            {
            r++;
            if(str[r]=='\0')
            break;
            }
            z[i]=r-l;
        }
        else
        {
            if(z[i-l]+i>=r)
            {
                l=i;
                i--;
            }
            else
            {
                z[i]=z[i-l];
            }
        }
    }
    for(i=0;i<strlen(str);i++)
    printf("%d ",z[i]);
    for(i=0;i<strlen(str);i++)
    {
        
        if(z[i]==len)
        return &str[i];
    }
    return NULL;
}
int main() {
    char str1[100],str2[100];
    scanf("%s",str1);
    scanf("%s",str2);
    len=strlen(str2);
    strcat(str2,str1);
    char *res=z_value(str2);
    printf("%s",res);
}
