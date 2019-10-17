/*
  Given a binary tree, return the zigzag level order traversal of its nodes’ values. 
  (ie, from left to right, then right to left for the next level and alternate between).

  Example :
  Given binary tree

      3
     / \
    9  20
      /  \
     15   7
  return

  [
           [3],
           [20, 9],
           [15, 7]
  ]
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    // queue<TreeNode*> stk;
    vector<vector<int>> res;
    if(root==NULL)
        return res;
    stack<TreeNode*> stk1;
    stack<TreeNode*> stk2;
    stk1.push(root);
    int f=1;
    while(stk1.size())
    {
        vector<int> v;
        while(stk1.size())
        {
            TreeNode *top = stk1.top();
            v.push_back(top->val);
            stk1.pop();
            if(f)
            {
                if(top->left)
                {
                    stk2.push(top->left);
                }
                if(top->right)
                {
                    stk2.push(top->right);
                }
            }
            else
            {
                if(top->right)
                {
                    stk2.push(top->right);
                }
                if(top->left)
                {
                    stk2.push(top->left);
                }
            }  
        }
        res.push_back(v);
        stk1.swap(stk2);
        f=!f;
    }
    return res;
}
    // stk.push(A);            // this method is simply doing inorder traversal and then reverse every even level traversal.
    // int f=0;
    // while(stk.size())
    // {
    //     int size = stk.size();
    //     int i=0;
    //     vector<int> v;
    //     while(i<size)
    //     {
    //         TreeNode *temp = stk.front();
    //         stk.pop();
    //         v.push_back(temp->val);
    //         if(temp->left)
    //         {
    //             stk.push(temp->left);
    //         }
    //         if(temp->right)
    //         {
    //             stk.push(temp->right);
    //         }
    //         i++;
    //     }
    //     if(f)
    //     reverse(v.begin(),v.end());
    //     res.push_back(v);
    //     f=!f;
    // }
//     return res;
// }
