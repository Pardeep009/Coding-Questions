/*
  Given a binary tree and two node values your task is to find the minimum distance between them.
  
  Example:
  Input
  1
  2
  1 2 L 1 3 R
  2 3 

  Output
  2
  
*/
Node *lca(Node *root,int a,int b)             // Finding Lowest common ancestor
{
    if(root == NULL)
    return NULL;
    
    if(root->data == a || root->data == b)
    return root;
    
    Node *left_lca = lca(root->left,a,b);
    Node *right_lca = lca(root->right,a,b);
    
    if(left_lca && right_lca)
    return root;
    
    return left_lca!=NULL?left_lca:right_lca;
    
}

int dist(Node *root,int a)
{
    if(root ==  NULL || root->data == a)
    return 0;
    
    if((root->left && root->left->data == a) || (root->right && root->right->data == a))
    return 1;
    
    int l = dist(root->left,a);
    if(l)
    {
        return l+1;
    }
    
    int r = dist(root->right,a);
    if(r)
    {
        return r+1;
    }
    
    return 0;
    
}

int findDist(Node* root, int a, int b)     // called from main
{
    if(a==b)
    return 0;
    Node *LCA = lca(root,a,b);
    int d1 = dist(LCA,a);                  // finding distance of a and b from LCA
    int d2 = dist(LCA,b);
    return d1+d2;
}
