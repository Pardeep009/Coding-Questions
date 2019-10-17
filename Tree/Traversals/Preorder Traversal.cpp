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
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
