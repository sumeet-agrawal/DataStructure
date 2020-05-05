#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack> 
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int q;
    cin>>q;
    stack<string> tag;
    for(int i =0;i<q;i++){
        int op, val;
        cin>>op;
        string sub;
        switch(op){
            case 1:
                cin>>sub;
                if(!tag.empty())
                    tag.push(tag.top()+sub);
                else
                    tag.push(sub);
                break;
            case 2:
            {
                cin>>val;
                string s = (tag.top()).substr(0,(tag.top()).length()-val);
                tag.push(s);
                break;
            }
            case 3:
            {
                cin>>val;
                cout<<tag.top()[val-1]<<endl;
                break;
            }
            case 4:
                tag.pop();
                break;
        }
    } 
    return 0;
}
