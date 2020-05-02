#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the cookies function below.
 */
class MinHeap{
public:
    vector<int> arr;
    int parent(int id){return (id-1)/2;}
    int left(int id){return 2*id +1;}
    int right(int id){return 2*id +2;}
    void insert(int data){
        int id = arr.size();
        arr.push_back(data);
        while(id!=0 && arr[id]<arr[parent(id)]){
            int temp = arr[id];
            arr[id] = arr[parent(id)];
            arr[parent(id)] = temp;
            id = parent(id);
        }
    }
    int extractMin(){
        int temp = arr[0];
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        MinHeapify(0);
        return temp;
    }
    void MinHeapify(int id){
        int smallest = id;
        int l = left(id);
        int r = right(id);
        if(l<arr.size() && arr[l]<arr[smallest])
            smallest = l;
        if(r<arr.size() && arr[r]<arr[smallest])
            smallest = r;
        if(smallest!=id){
            int temp = arr[id];
            arr[id] = arr[smallest];
            arr[smallest] = temp;
            MinHeapify(smallest);
        }
    }
};
int cookies(int k, vector<int> A) {
    /*
     * Write your code here.
     */
     MinHeap *heap = new MinHeap();
     for(int i=0;i<A.size();i++){
         heap->insert(A[i]);
     }
     int count = 0;int num1, num2;
     num1 = heap->extractMin();
     while(num1<k && heap->arr.size()>0){
         num2 = heap->extractMin();
         heap->insert(num1+(2*num2));
         count++;
         num1 = heap->extractMin();
     }
     return num1>=k?count:-1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<int> A(n);

    for (int A_itr = 0; A_itr < n; A_itr++) {
        int A_item = stoi(A_temp[A_itr]);

        A[A_itr] = A_item;
    }

    int result = cookies(k, A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
