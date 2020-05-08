/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
	bool checkBST(Node* root) {
		if(!root)
            return true;
        bool retl = true, retr = true;
        if(root->left)
            retl = (root->left->data<root->data) && checkBST(root->left);
        if(root->right)
            retr = (root->right->data>root->data) && checkBST(root->right);
        return retl && retr;
	}
