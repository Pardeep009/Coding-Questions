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
