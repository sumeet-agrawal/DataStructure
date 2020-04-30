#include <bits/stdc++.h>	

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

    void levelOrder(Node * root) {
        Node** arr;int i=0,j=0;
        arr =(Node**)malloc(sizeof(Node*));
        arr[i] = root;
        while(i<=j){
            if(arr[i]->left){
                j++;
                arr=(Node**)realloc(arr,(j+1)*sizeof(Node*));
                arr[j] = arr[i]->left;
            }
            if(arr[i]->right){
                j++;
                arr=(Node**)realloc(arr,(j+1)*sizeof(Node*));
                arr[j] = arr[i]->right;
            }
            i++;
        }
        i=0;
        while(i<=j){
            cout<<arr[i]->data<<" ";
            i++;
        }
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.levelOrder(root);
    return 0;
}
