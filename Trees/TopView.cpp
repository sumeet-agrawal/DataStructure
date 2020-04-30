#include<bits/stdc++.h>

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

class nd {
    public:
        int data;
        int level;
        nd *left;
        nd *right;
        nd(int d,  int l) {
            data = d;
            left = NULL;
            right = NULL;
            level = l;
        }
};
    void append(Node* root, nd* list, int lev){
        if(root->left){
            if(list->left){
                if(lev+1<list->left->level){
                    list->left->data = root->left->data;
                    list->left->level = lev +1;
                }
            }else{
                list->left = new nd(root->left->data,lev+1);
                list->left->right = list;
            }
            append(root->left,list->left,lev+1);
        }
        if(root->right){
            if(list->right){
                if(lev+1<list->right->level){
                    list->right->data = root->right->data;
                    list->right->level = lev+1;
                }
            }else{
                list->right = new nd(root->right->data,lev+1);
                list->right->left = list;
            }
            append(root->right,list->right,lev+1);
        }
    }
    void topView(Node * root) {
        nd* list = new nd(root->data,0);
        append(root, list, 0);
        nd* temp = list;
        while(temp->left){
            temp = temp->left;
        }
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->right;
        }
    }

}; //End of Solution
