#include<iostream>
using namespace std;
#define SIZE 5
int arr[SIZE];
int top1 = -1;
int top2 = SIZE;

void push1()
{
    if(top1+1==top2)
    {
        cout<<"Stack is FUll"<<endl;
    }
    else
    {
        int ele;
        cin>>ele;
        arr[++top1] = ele;
    }
}

void pop1()
{
    if(top1==-1)
    {
        cout<<"Stack is Empty"<<endl;
    }
    else
    {
        cout<<"Popped Element is "<<arr[top1--]<<endl;
    }
    
}

void push2()
{
    if(top1+1==top2)
    {
        cout<<"Stack is FUll"<<endl;
    }
    else
    {
        int ele;
        cin>>ele;
        arr[--top2] = ele;
    }
}

void pop2()
{
    if(top2==SIZE)
    {
        cout<<"Stack is Empty"<<endl;
    }
    else
    {
        cout<<"Popped Element is "<<arr[top2++]<<endl;
    }
}

void printStack1()
{
    int i=0;
    while(i<=top1)
    {
        cout<<arr[i]<<" ";
        i++;
    }
}

void printStack2()
{
    int i=SIZE-1;
    while(i>=top2)
    {
        cout<<arr[i]<<" ";
        i--;
    }
}

int main()
{
    int op;
    cout<<"Enter 1 for first Stack Operation"<<endl;
    cout<<"Enter 2 for Second Stack Operation"<<endl;
    cin>>op;
    while(op!=-1)
    {
        if(op==1)
        {
            cout<<"Enter 1 for push"<<endl;
            cout<<"Enter 2 for pop"<<endl;
            cin>>op;
            if(op==1)
            {
                cout<<"Enter Element"<<endl;
                push1();
            }
            else if(op==2)
            {
                pop1();
            }
        }
        else if(op==2)
        {
            cout<<"Enter 1 for push"<<endl;
            cout<<"Enter 2 for pop"<<endl;
            cin>>op;
            if(op==1)
            {
                cout<<"Enter Element"<<endl;
                push2();
            }
            else if(op==2)
            {
                pop2();
            }
        }
        cout<<"Enter 1 for first Stack Operation"<<endl;
        cout<<"Enter 2 for Second Stack Operation"<<endl;
        cin>>op;
    }
    printStack1();
    printStack2();
}
