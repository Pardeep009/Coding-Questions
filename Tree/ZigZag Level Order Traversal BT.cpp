/*
  Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

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

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    queue<TreeNode*> stk;
    vector<vector<int>> res;
    stk.push(A);
    int f=0;
    while(stk.size())
    {
        int size = stk.size();
        int i=0;
        vector<int> v;
        while(i<size)
        {
            TreeNode *temp = stk.front();
            stk.pop();
            v.push_back(temp->val);
            if(temp->left)
            {
                stk.push(temp->left);
            }
            if(temp->right)
            {
                stk.push(temp->right);
            }
            i++;
        }
        if(f)
        reverse(v.begin(),v.end());
        res.push_back(v);
        f=!f;
    }
    return res;
}
