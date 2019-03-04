// special chars are 0X24
#include<stdio.h>
#include<stdlib.h>
void rem_spa(char *s)
{
	int i=0,j=0,f=0;
	while(s[i]!='\0')
	{
		if(s[i]==' ')
		{
			if(f==1)
			{
				s[j++]=' ';
			}
			f=0;
		}
		else
		{
			f=1;
			s[j++]=s[i];
		}
		i++;
	}
	if(s[j-1]==' ')
	s[j-1]='\0';
	s[j]='\0';
}
int cnt_wc(char *s)
{
	int f=0,i=0,cnt=0;
	while(s[i]!='\0')
	{
		if(s[i]==' ')
		{
			f=0;
		}
		else
		{
			if(f==0)
			{
				cnt++;
				f=1;
			}
		}
		i++;
	}
	return cnt;
}
void add_chars(char *str)
{
	rem_spa(str);
	int cnt=cnt_wc(str);
	cnt--;
	int i=0,l=0,k=0;
	for(i=0;str[i]!='\0';i++)
	{
		l++;
	}
	str[l+cnt*4-cnt]='\0';
	k=l+cnt*4-cnt-1;
	l--;
	while(k>0)
	{
		while(str[l]!=' '&&l>=0)
		{
			str[k--]=str[l--];
		}
		if(l<0||k<0)
		break;
		str[k--]='4';
		str[k--]='2';
		str[k--]='X';
		str[k--]='0';
		l--;
	}
}
int main()
{
	char *str=(char*)malloc(100);
	scanf("%[^\n]s",str);     // my name is pardeep bhatt
	add_chars(str);
	puts(str);        		  // my0X24name0X24is0X24pardeep0X24bhatt
}
