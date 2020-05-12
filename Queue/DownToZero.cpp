#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int main(){
    vector<int> arr(MAX);
    for(int i=0;i<MAX;i++)
        arr[i]=-1;
    arr[0]=0;
    for(int i=1;i<MAX;i++){
        if(arr[i]==-1 || arr[i-1]+1<arr[i])
            arr[i]=arr[i-1]+1;
        for(int j=1;(i*j)<MAX && j<=i;j++){
            if(arr[i*j]==-1 || (arr[i]+1)<arr[i*j])
                arr[i*j]=arr[i]+1;
        }
    }
    int q;cin>>q;
    for(int i =0;i<q;i++){
        int num;cin>>num;
        cout<<arr[num]<<endl;
    }
    return 0;    
}
