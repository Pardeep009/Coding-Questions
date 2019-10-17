/*
  Given preorder and inorder traversal of a tree, construct the binary tree.
  
  Example :
  Input :
          Preorder : [1, 2, 3]
          Inorder  : [2, 1, 3]

  Return :
              1
             / \
            2   3
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
 TreeNode *buildUtil(vector<int> &preorder,vector<int>& inorder,int &pre,int start,int end)
{
    if(start>end)
    return NULL;
    
    TreeNode *temp = new TreeNode(preorder[pre++]);
    
    if(start ==  end)
    return temp;
    
    int search=0;
    for(int i=start;i<=end;i++)
    {
        if(inorder[i] == temp->val)
        {
            search = i;
            break;
        }
    }
    
    temp->left = buildUtil(preorder,inorder,pre,start,search-1);
    temp->right = buildUtil(preorder,inorder,pre,search+1,end);
    
    return temp;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int pre=0;
    int start=0;
    int end=A.size()-1;
    return buildUtil(A,B,pre,start,end);
}
