#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the waiter function below.
 */

vector<int> waiter(vector<int> number, int q) {
    vector<int> primes(50000,1);
    vector<int> primeList;
    for(int i =2;i<50000;i++){
        if(primes[i]){
            primeList.push_back(i);
            for(int j=i+1;j<=50000;j++){
                if(primes[j])
                    if(j%i ==0)
                        primes[j]=0;
            }
        }
    }
    vector<stack<int>> A;
    vector<stack<int>> B;
    stack<int> A0;
    for(int i =0;i<number.size();i++){
        A0.push(number[i]);
    }
    A.push_back(A0);
    for(int i=0;i<q;i++){
        stack<int> a,b;
        while(!A[i].empty()){
            if(A[i].top()%primeList[i]==0){
                b.push(A[i].top());
            }else{
                a.push(A[i].top());
            }
            A[i].pop();
        }
        B.push_back(b);
        A.push_back(a);
    }
    vector<int> ans;
    for(int i=0;i<q;i++){
        while(!B[i].empty()){
            ans.push_back(B[i].top());
            B[i].pop();
        }
    }
    while(!A[A.size()-1].empty()){
        ans.push_back(A[A.size()-1].top());
        A[A.size()-1].pop();
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split_string(number_temp_temp);

    vector<int> number(n);

    for (int number_itr = 0; number_itr < n; number_itr++) {
        int number_item = stoi(number_temp[number_itr]);

        number[number_itr] = number_item;
    }

    vector<int> result = waiter(number, q);

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
