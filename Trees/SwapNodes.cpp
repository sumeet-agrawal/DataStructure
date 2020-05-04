#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* next;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
void swapAtK(Node* root, int k,int h){
    if(!root)
        return;
    cout<<"swapatK "<<k<<" "<<h<<" "<<root->data<<endl;
    if(h==k){
        cout<<"swapping start "<<root->data<<endl;
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        cout<<"swapping done "<<root->data<<endl;
    }
    else{
        swapAtK(root->left, k, h+1);
        swapAtK(root->right,k, h+1);
    }
}
int height(Node* root){
    if(!root){
        return -1;
    }
    int l = height(root->left);
    int r = height(root->right);
    return (1 + (l>r?l:r));
}
vector<int> globalarr;
void generate(Node* root){
    if(!root)
        return;
    generate(root->left);
    globalarr.push_back(root->data);
    generate(root->right);
    return;
}
vector<vector<int>> swap(Node* root, vector<int> queries){
    int h = height(root) +1;
    vector<vector<int>> arr;
    for(int i =0;i<queries.size();i++){
        for(int j=1;queries[i]*j<=h;j++){
            cout<<"swap "<<queries[i]*j<<endl;
            swapAtK(root, queries[i]*j,1);
        }
        generate(root);
        arr.push_back(globalarr);
        globalarr.clear();
    }
    return arr;
}
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    Node *tail, *head, *temp;
    head = new Node(1);
    tail = head;
    temp = head;
    for(int i =0;i<indexes.size() && temp;i++){
        if(indexes[i][0]==-1){
            temp->left = NULL;
        }else{
            Node* nd = new Node(indexes[i][0]);
            temp->left = nd;
            tail->next = nd;
            tail = tail->next;
        }
        if(indexes[i][1]==-1){
            temp->right = NULL;
        }else{
            Node* nd = new Node(indexes[i][1]);
            temp->right = nd;
            tail->next = nd;
            tail = tail->next;
        }
        temp = temp->next;
    }
    return swap(head, queries);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
