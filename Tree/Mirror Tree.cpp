/*
  Given a binary tree, create mirror(inverting the binary tree) of tree and return it.
  Look at the example for more details.
  
  Example :
  Given binary tree

       1
     /   \
    2     3
   / \   / \
  4   5 6   7
  
  Mirror(invert)
       1
     /   \
    3     2
   / \   / \
  7   6 5   4
  
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
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL)
    return A;
    TreeNode *temp=NULL;
    TreeNode *lt=NULL,*rt=NULL;
    queue<TreeNode*> q;
    q.push(A);
    while(q.size())
    {
        temp = q.front();
        q.pop();
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        lt = temp->left;
        rt = temp->right;
        temp->left = rt;
        temp->right = lt;
    }
    return A;
}
