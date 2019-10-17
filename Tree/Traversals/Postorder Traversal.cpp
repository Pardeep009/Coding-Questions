/*
  Given a binary tree, return the postorder traversal of its nodes’ values.

  Example :
  Given binary tree

     1
      \
       2
      /
     3
  return [3,2,1].

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
vector<int> Solution::postorderTraversal(TreeNode* A) {
            stack<TreeNode*> stk;
            vector<int> res;
            //base case
            if(root==NULL)
                return res;
            stk.push(root);
            TreeNode* temp=NULL;  
            while(stk.size()) 
            {
                temp = stk.top();
                res.push_back(temp->val);
                stk.pop();
                if(temp->left)
                    stk.push(temp->left);
                if(temp->right)
                    stk.push(temp->right);
            }
            reverse(res.begin(),res.end());
            return res;
}
