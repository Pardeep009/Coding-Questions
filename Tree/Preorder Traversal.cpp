/*
  Given a binary tree, return the preorder traversal of its nodes’ values.
  Example :
  Given binary tree

     1
      \
       2
      /
     3
  return [1,2,3].
  
*/
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode *temp;
    stk.push(A);
    while(stk.size())
    {
        temp = stk.top();
        stk.pop();
        res.push_back(temp->val);
        if(temp->right)
        {
            stk.push(temp->right);
        }
        if(temp->left)
        {
            stk.push(temp->left);
        }
    }
    return res;
}
