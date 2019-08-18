/*
  Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
  Example :
      1
     / \
    2   2
   / \ / \
  3  4 4  3
  The above binary tree is symmetric.
  
  But the following is not:

      1
     / \
    2   2
     \   \
     3    3
  Return 0 / 1 ( 0 for false, 1 for true ) for this problem

*/
int Solution::isSymmetric(TreeNode* A) {
    queue<TreeNode*> q;
    TreeNode *left=NULL,*right=NULL;
    q.push(A);
    q.push(A);
    while(q.size())
    {
        left = q.front();
        q.pop();
        
        right = q.front();
        q.pop();
        
        if((!left&&right) || (left&&!right))
        return 0;
        
        if(left==NULL && right==NULL)
        continue;
        
        if(left->val!=right->val)
        return 0;
        
        q.push(left->left);
        q.push(right->right);
        
        q.push(left->right);
        q.push(right->left);
        
    }
    return 1;
}
