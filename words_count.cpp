#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class Word
{
	public:
	char stu[20];
	int cnt;
	Word *next;
};
class Hash
{
	public:
	Word *head;
	Hash()
	{
		head=NULL;
	}
};
void rem_spa(char s[])
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
	s[j]='\0';
}
Hash H[256];
int main()
{
	Word *ptr=NULL,*ptr1=NULL;
	int i=0,k=0,f=1;
	char str[100],s[20];
	cout<<"Enter a String Sir"<<endl;
	scanf("%[^\n]s",&str);
	rem_spa(str);
	cout<<str<<endl;
	while(str[i]!='\0')
	{
		if(str[i]==' '||str[i+1]=='\0')
		{
			if(str[i+1]=='\0')
			{
				s[k++]=str[i];
			}
			s[k]='\0';
			if(H[(int)s[0]].head==NULL)
			{
				ptr=new Word();
				strcpy(ptr->stu,s);
				ptr->cnt=1;
				ptr->next=NULL;
				H[(int)s[0]].head=ptr;
			}
			else
			{
				ptr=H[(int)s[0]].head;
				while(ptr->next!=NULL)
				{
					if(strcmp(ptr->stu,s)==0)
					{
						ptr->cnt++;
						f=0;
						break;
					}
					ptr=ptr->next;
				}
				if(strcmp(ptr->stu,s)==0&&f)
				{
					ptr->cnt++;
				}
				else if(f)   //if(ptr->next==NULL)
				{
					ptr1=new Word();
					strcpy(ptr1->stu,s);
					ptr1->cnt=1;
					ptr1->next=NULL;
					ptr->next=ptr1;
				}
			}
			f=1;
			k=0;
			s[0]='\0';
		}
		else
		{
			s[k++]=str[i];
		}
		i++;
	}
	for(i=0;i<256;i++)
	{
		if(H[i].head)
		{
			ptr=H[i].head;
			while(ptr!=NULL)
			{
				cout<<ptr->stu<<" occurs "<<ptr->cnt<<" times "<<endl;
				ptr=ptr->next;
			}
		}
	}
}