#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class MinHeap{
public:
    vector<int> arr;
    int parent(int id){ return (id-1)/2;}
    int left(int id){ return 2*id +1;}
    int right(int id){ return 2*id +2;}
    void insert(int data){
        //cout<<"Insert "<<data<<endl;
        int id = arr.size();
        arr.push_back(data);
        while(id!=0 && arr[id]<arr[parent(id)]){
            //cout<<"replace parent data "<<arr[parent(id)]<<endl;
            int temp = arr[id];
            arr[id] = arr[parent(id)];
            arr[parent(id)] = temp;
            id = parent(id);
        }
    }
    void del(int data){
        //cout<<"Delete "<<data<<endl;
        int id;
        for(id = 0;id<arr.size();id++){
            if(arr[id] == data)
                break;
        }
        //cout<<"data at index "<<id<<endl;
        arr[id] = INT32_MIN;
        while(id!=0 && arr[id]<arr[parent(id)]){
            //cout<<"replace parent data "<<arr[parent(id)]<<endl;
            int temp = arr[id];
            arr[id] = arr[parent(id)];
            arr[parent(id)] = temp;
            id = parent(id);
        }
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        MinHeapify(0);
    }
    void MinHeapify(int id){
        //cout<<"MinHeapify "<<id<<" data "<<arr[id]<<" "<<arr[parent(id)]<<endl;
        int smallest = id;
        int l = left(id);
        int r = right(id);
        if(l<arr.size() && arr[l]<arr[smallest])
            smallest = l;
        if(r<arr.size() && arr[r]<arr[smallest])
            smallest = r;
        if(smallest != id){
            int temp = arr[smallest];
            arr[smallest] = arr[id];
            arr[id] = temp;
            MinHeapify(smallest);
        }
    }
    void printMin(){
        //cout<<arr.size()<<" "<<arr[0]<<endl;
        cout<<arr[0]<<endl;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin>>q;
    MinHeap *heap = new MinHeap();
    for(int i =0;i<q;i++){
        int a,b;
        cin>>a;
        switch(a){
            case 1:
                cin>>b;
                heap->insert(b);
                //heap->printMin();
                break;
            case 2:
                cin>>b;
                heap->del(b);
                //heap->printMin();
                break;
            case 3:
                //cout<<"Output ";
                heap->printMin();
                break;
        }
    }
    return 0;
}
