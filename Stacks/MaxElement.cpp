#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<pair<int,int>> stack;
    int top =-1;
    int max=-1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a ;
        cin>>a;
        switch(a){
            case 1:
                int b;
                cin>>b;
                if(b>max)max = b;
                top++;
                if(top == stack.size()){
                    stack.push_back(make_pair(b,max));
                }else{
                    stack[top] = make_pair(b,max);
                }
               // cout<<b<<" "<<max<<" "<<stack.size();
                break;
            case 2:
                top--;
                if(top==-1)max = -1;
                else max = stack[top].second;
                break;
            case 3:
                cout<<stack[top].second<<endl;
                break;
        }
    } 
    return 0;
}
