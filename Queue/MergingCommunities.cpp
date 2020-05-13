#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*int findroot(vector<int> &vec, int num){
    return vec[num]==num?num:findroot(vec,vec[num]);
}*/
int findroot(vector<int> &vec,int num){
    if(num!=vec[num])vec[num] = findroot(vec,vec[num]);
    return vec[num];
}

int main() {
    int n,q;
    cin>>n>>q;
    vector<int> parent(n+1);
    vector<int> count(n+1);
    for(int i =1;i<n+1;i++){
        parent[i] = i;
        count[i] = 1;
    }
    for(int i=0;i<q;i++){
        char ch;cin>>ch;
        int a,b;cin>>a;
        if(ch=='M'){
            cin>>b;
            int ra = findroot(parent,a);
            int rb = findroot(parent,b);
            if(ra==rb)continue;
            parent[ra]=rb;
            count[rb]=count[ra]+count[rb];
            count[ra]=0;
        }else{
            cout<<count[findroot(parent,a)]<<endl;
        }
    }
    return 0;
}
