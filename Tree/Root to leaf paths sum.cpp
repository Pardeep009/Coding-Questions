long long total_sum(Node *root,long long sum)
{
    if(root == NULL)
    return sum;
    
    sum = sum*10 + root->data;
    
    if(root->left==NULL && root->right == NULL)
    return sum;
    
    return total_sum(root->left,sum) + total_sum(root->right,sum);
    
}
long long treePathsSum(Node *root)
{
    //Your code here
    return total_sum(root,0);
}
