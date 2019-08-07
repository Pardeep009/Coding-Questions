/*
    Problem Link:-> https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
    Given a binary tree, return a 2-D array with vertical order traversal of it.
    Go through the example for more details.

    Example :
    Given binary tree:
            
          6
        /   \
       3     7
      / \     \
     2   5     9
     
     returns                      
     [
        [2],
        [3],
        [6 5],
        [7],
        [9]
     ]  
     
*/
vector<vector<int>> Solution::verticalOrderTraversal(TreeNode* A) {
    map<int,vector<int>> m;
    queue<pair<TreeNode*,int>> q;
    int hrz;
    TreeNode *temp=NULL;
    q.push({A,0});
    if(A!=NULL)
    while(q.size())
    {
        temp=q.front().first;
        hrz=q.front().second;
        m[hrz].push_back(temp->val);
        if(temp->left)
        {
            q.push({temp->left,hrz-1});
        }
        if(temp->right)
        {
            q.push({temp->right,hrz+1});
        }
        q.pop();
    }
    vector<vector<int>> ans;
    for(auto it=m.begin();it!=m.end();it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}
