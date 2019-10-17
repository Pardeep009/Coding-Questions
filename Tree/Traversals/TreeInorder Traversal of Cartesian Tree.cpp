/*
  Given an inorder traversal of a cartesian tree(root element is maximum than its subtrees), construct the tree.
  
  Example :
  Input : [1 2 3]

  Return :   
            3
           /
          2
         /
        1
*/
int maxIndex(vector<int> &A,int start,int end)
{
    int max = start;
    for(int i=start+1;i<=end;i++)
    {
        max = A[max]>A[i]?max:i;
    }
    return max;
}

TreeNode *build(vector<int> &A,int start,int end)
{
    if(start>end)
    return NULL;
    
    int i = maxIndex(A,start,end);
    
    TreeNode *root = new TreeNode(A[i]);
    
    if(start==end)
    return root;
    
    root->left = build(A,start,i-1);
    root->right = build(A,i+1,end);
    
    return root;
    
}

TreeNode* Solution::buildTree(vector<int> &A) {          // called from main
    int start = 0;
    int end = A.size()-1;
    return build(A,start,end);
}
