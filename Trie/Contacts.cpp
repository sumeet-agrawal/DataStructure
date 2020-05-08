#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the contacts function below.
 */
class Trie{
public:
    vector<Trie*> next;
    int total;
    bool isleaf;
    Trie(bool leaf=0){
        for(int i=0;i<26;i++){
            next.push_back(NULL);
        }
        isleaf = leaf;
        total = 0;
    }
    void add(string str){
        //cout<<"add "<<str<<endl;
        Trie* temp = this;
        for(int i =0;i<str.length();i++){
            //cout<<"add "<<str[i]<<" "<<temp<<endl;
            if(!temp->next[str[i]-'a']){
                //cout<<"new"<<endl;
                temp->next[str[i]-'a'] = new Trie(i==(str.length()-1));
            }
            temp = temp->next[str[i]-'a'];
            temp->total++;
        }
    }
    int find(string str){
        //cout<<str<<endl;
        Trie* temp = this;
        for(int i=0;i<str.length();i++){
            //cout<<str[i]<<" "<<temp<<endl;
            temp = temp->next[str[i]-'a'];
            if(!temp)
                return 0;
        }
        return temp->total;
    }
};
vector<int> contacts(vector<vector<string>> queries) {
    Trie* dic = new Trie();
    vector<int> ans;
    cout<<queries.size()<<endl;
    for(int i=0;i<queries.size();i++){
        if(!queries[i][0].compare("add")){
            dic->add(queries[i][1]);
        }else{
            ans.push_back(dic->find(queries[i][1]));
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
