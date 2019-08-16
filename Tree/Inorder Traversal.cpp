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
    TreeNode *prev=A;
    while(stk.size() || prev)
    {
        if(prev)
        {
            stk.push(prev);
            prev = prev->left;
        }
        else
        {
            prev = stk.top();
            stk.pop();
            res.push_back(prev->val);
            prev = prev->right;
        }
    }
    return res;
}
