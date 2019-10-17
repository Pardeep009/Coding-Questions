#include<bits/stdc++.h>
using namespace std;

struct Tree
{
    int data;
    Tree *left;
    Tree *right;
};

void insert(Tree* &root,Tree *temp)
{
    if(root == NULL)
    {
        root = temp;
        temp->left = NULL;
        temp->right = NULL;
    }
    else if(temp->data>root->data)
    {
        if(root->right==NULL)
        {
            root->right = temp;
        }
        else
        {
            insert(root->right,temp);
        }
        
    }
    else
    {
        if(root->left==NULL)
        {
            root->left = temp;
        }
        else
        {
            insert(root->left,temp);
        }
        
    }
}

vector<int> maxpathsum(Tree *root,int &sum)
{
    if(root==NULL)
    {
        sum=0;
        return vector<int>{};
    }

    sum += root->data;

    int left_sum = 0;
    int right_sum = 0;
    vector<int> lt = maxpathsum(root->left,left_sum);
    vector<int> rt = maxpathsum(root->right,right_sum);
    
    if(left_sum>right_sum)
    {
        // max_sum += left_sum;
        lt.push_back(root->data);
        return lt;
    }
    else
    {
        // max_sum += right_sum;
        rt.push_back(root->data);
        return rt;
    }
}

int main()
{
    Tree *root=NULL;
    int n;
    cin>>n;
    while(n!=-1)
    {
        Tree *temp = new Tree();
        temp->data = n;
        insert(root,temp);
        cin>>n;
    }
    print(root);
    cout<<endl;
    int sum=0;
    vector<int> v = maxpathsum(root,sum);
    for(auto it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
}
