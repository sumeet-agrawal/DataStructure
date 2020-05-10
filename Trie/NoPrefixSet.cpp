#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Trie{
public:
    vector<Trie*> vec;
    bool isLeaf;
    Trie(bool leaf){
        vec.resize(26);
        isLeaf= leaf;
    }
    bool add(string str){
        //cout<<"add "<<str<<endl;
        Trie *temp = this;
        for(int i=0;i<str.length();i++){
            if(temp->isLeaf)
                return false;
            if(!temp->vec[str[i]-'a']){
                temp->vec[str[i]-'a'] = new Trie(i==(str.length()-1));
            }else{
                if(i==(str.length()-1))
                    return false;
            }            
            temp = temp->vec[str[i]-'a'];
        }
        return true;
    }
};
int main() {
    int num;
    cin>>num;
    Trie* pTree = new Trie(false);
    bool flag = true;
    string out;
    for(int i=0;i<num;i++){
        string str;
        cin>>str;
        if(flag){
            flag = pTree->add(str);
            //cout<<flag<<" "<<str<<endl;
            out = str;
        }
    }
    if(flag){
        cout<<"GOOD SET"<<endl;
    }else{
        cout<<"BAD SET"<<endl<<out<<endl;
    }
    return 0;
}
