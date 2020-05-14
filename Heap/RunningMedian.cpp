#include <bits/stdc++.h>

using namespace std;

class Heap{
public:    
    vector<int> arr;
    int parent(int id){ return (id-1)/2;}
    int left(int id){ return 2*id +1;}
    int right(int id){ return 2*id +2;}
    virtual void insert(int data) = 0;
    virtual void heapify(int id) = 0;
    int extract(){
        int temp = arr[0];
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        heapify(0);
        return temp;
    }
    void swap(int &a,int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    int size(){ return arr.size();}
    int top(){ return arr[0];}
};
class MinHeap : public Heap{
public:
    void insert(int data){
        int n = arr.size();
        arr.push_back(data);
        while(parent(n)>=0 && arr[n]<arr[parent(n)]){
            swap(arr[n],arr[parent(n)]);
            n = parent(n);
        }
    }
    void heapify(int id){
        int smallest = id;
        int l = left(id);
        int r = right(id);
        if(l<arr.size() && arr[l]<arr[smallest])
            smallest = l;
        if(r<arr.size() && arr[r]<arr[smallest])
            smallest = r;
        if(smallest!=id){
            swap(arr[id],arr[smallest]);
            heapify(smallest);
        }
    }
    
};
class MaxHeap : public Heap{
public:
    void insert(int data){
        int n = arr.size();
        arr.push_back(data);
        while(parent(n)>=0 && arr[n]>arr[parent(n)]){
            swap(arr[n],arr[parent(n)]);
            n = parent(n);
        }
    }
    void heapify(int id){
        int largest = id;
        int l = left(id);
        int r = right(id);
        if(l<arr.size() && arr[l]>arr[largest])
            largest = l;
        if(r<arr.size() && arr[r]>arr[largest])
            largest = r;
        if(largest!=id){
            swap(arr[id],arr[largest]);
            heapify(largest);
        }
    }
};

int main()
{
    int n,num;
    cin>>n>>num;
    MinHeap* min = new MinHeap();
    MaxHeap* max = new MaxHeap();
    max->insert(num);
    double mid=(double)num;
    printf("%0.1f\n",mid);
    for(int i =1;i<n;i++){
        cin>>num;
        if(min->size()==max->size()){
            if(num>mid){
                min->insert(num);
                mid = (double)min->top();
            }else{
                max->insert(num);
                mid = (double)max->top();
            }
        }else if(min->size()<max->size()){
            if(num>mid){
                min->insert(num);
            }else{
                max->insert(num);
                min->insert(max->extract());
            }
            mid = (double)(min->top() + max->top())/2;
        }else{
            if(num>mid){
                min->insert(num);
                //cout<<min->size()<<" "<<max->size()<<endl;
                int te = min->extract();
                //cout<<num<<" "<<te<<" "<<min->top()<<endl;
                max->insert(te);
            }else{
                max->insert(num);
            }
            mid = (double)(min->top() + max->top())/2;
        }
        //cout<<"Every list "<<num<<" "<<max->top()<<" "<<min->top()<<endl;
        printf("%0.1f\n",mid);
    }
    return 0;
}
