/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */
int height(node* root){
    if(!root)
        return -1;
    return root->ht;
}

node *newnode(int val){
    node* nd = (node*)malloc(sizeof(node));
    nd->val = val;
    nd->left = nullptr;
    nd->right = nullptr;
    nd->ht = 0;
    return nd;
}

int getbalance(node* root){
    if(!root)
        return -1;
    return height(root->left)-height(root->right);
}

int max (int a , int b){
    return a>b?a:b;
}
node* leftrotate(node* root){
    node* t1 = root;
    node* t2 = root->right;
    
    t1->right = t2->left;
    t2->left = t1;
    
    t1->ht = 1+ max(height(t1->left),height(t1->right));
    t2->ht = 1+ max(height(t1->left),height(t2->right));
    return t2;
}
node* rightrotate(node* root){
    node* t1 = root;
    node* t2 = root->left;
    
    t1->left = t2->right;
    t2->right = t1;
    
    t1->ht = 1+ max(height(t1->left),height(t1->right));
    t2->ht = 1+ max(height(t1->left),height(t2->right));
    return t2;
}
node * insert(node * root,int val)
{
	if(!root)
        return newnode(val);
    if(val<root->val)
        root->left = insert(root->left,val);
    else
        root->right = insert(root->right, val);
    
    
    root->ht = 1+ max(height(root->left),height(root->right));
    
    int bf = getbalance(root);
    if(bf>1){
        if(val>root->left->val){
            root->left = leftrotate(root->left);
            return rightrotate(root);
        }else{
            return rightrotate(root);
        }
    }else if(bf<-1){
        if(val>root->right->val){
            return leftrotate(root);
        }else{
            root->right = rightrotate(root->right);
            return leftrotate(root);
        }
    }
    return root;
}
