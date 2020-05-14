#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;cin>>t;
    for(int i =0;i<t;i++){
        int n,m;cin>>n>>m;
        vector<vector<int>> arr;
        for(int j=0;j<m;j++){
            string str;cin>>str;
            //cout<<arr.size()<<" "<<str<<endl;
            if(!str.compare("UPDATE")){
                //cout<<str<<endl;
                int x,y,z,w,flag=0;
                cin>>x>>y>>z>>w;
                for(int k=0;k<arr.size();k++){
                    if(arr[k][0]==x && arr[k][1]==y && arr[k][2]==z){
                        arr[k][3] = w;
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    vector<int> temp ={x,y,z,w};
                    arr.push_back(temp);
                }
            }else{
                int x1,y1,z1,x2,y2,z2;
                cin>>x1>>y1>>z1>>x2>>y2>>z2;
                long long sum = 0;
                for(int k=0;k<arr.size();k++){
                    if(arr[k][0]>=x1 && arr[k][0]<=x2 && arr[k][1]>=y1 && arr[k][1]<=y2 && arr[k][2]>=z1 && arr[k][2]<=z2){
                        sum+=arr[k][3];
                    }
                }
                cout<<sum<<endl;
            }
        }
    }

    return 0;
}
