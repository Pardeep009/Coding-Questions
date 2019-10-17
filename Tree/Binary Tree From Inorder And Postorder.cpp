/*
  Given inorder and postorder traversal of a tree, construct the binary tree.

  Example :

  Input : 
          Inorder : [2, 1, 3]
          Postorder : [2, 3, 1]

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
 TreeNode *buildUtil(vector<int> &postorder,vector<int>& inorder,int &pre,int start,int end)
{
    if(start>end)
    return NULL;
    
    TreeNode *temp = new TreeNode(postorder[pre--]);
    
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
    
    temp->right = buildUtil(postorder,inorder,pre,search+1,end);
    temp->left = buildUtil(postorder,inorder,pre,start,search-1);
    
    return temp;
    
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    int post=B.size()-1;
    int start=0;
    int end=A.size()-1;
    return buildUtil(B,A,post,start,end);
    
}
