/*
  Given a binary tree in which each node element contains a number.
  Find the maximum possible sum from one leaf node to another.
*/
  int maxsum(Node *root,int &sum)
{
    if(root==NULL)
    return 0;
    
    int lt = maxsum(root->left,sum);
    
    int rt = maxsum(root->right,sum);
    
    if(root->data+lt+rt>sum)
    sum = root->data+lt+rt;
    
    lt+=root->data;
    rt+=root->data;
    
    return lt>rt?lt:rt;
    
}
int maxPathSum(struct Node *root)      // called from main
{
//add code here.
    if(root==NULL)
    return 0;
    int sum=0;
    maxsum(root,sum);
    return sum;
}
