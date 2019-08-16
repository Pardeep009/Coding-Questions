/*
  
  Given a binary tree, return the inorder traversal of its nodes’ values.
  Example :
  Given binary tree

     1
      \
       2
      /
     3
  return [1,3,2].
  
*/
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode*> stk;
    stk.push(A);
    TreeNode *temp;
    while(stk.size())
    {
        temp = stk.top();
        if(temp->left)
        {
            stk.push(temp->left);
            temp->left = NULL;
        }
        else
        {
            stk.pop();
            res.push_back(temp->val);
            if(temp->right)
            {
                stk.push(temp->right);
                temp->right = NULL;
            }
        }
    }
    return res;
}
