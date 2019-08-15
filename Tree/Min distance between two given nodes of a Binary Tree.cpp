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
  /*                                    // queue based solution,for finding distance of a and b from LCA
     queue<Node*> q;
    q.push(LCA);
    int level=0;
    int ans=0;
    int f1=1,f2=1;
    while(q.size() && f1|f2)
    {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            Node *temp = q.front();
            q.pop();
            if(temp->data == a)
            {
                ans+=level;
                f1=0;
            }
            if(temp->data == b)
            {
                ans+=level;
                f2=0;
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        level++;
    }
    return ans;
  */
