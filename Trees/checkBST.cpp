/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
vector<int> arr;
void check(Node* root){
    if(!root)
        return;
    check(root->left);
    arr.push_back(root->data);
    check(root->right);
}
	bool checkBST(Node* root) {
		check(root);
        for(int i =1;i<arr.size();i++){
            //cout<<arr[i]<<" ";
            if(arr[i]<=arr[i-1])
                return false;
        }
        return true;        
	}
