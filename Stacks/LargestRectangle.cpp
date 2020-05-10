#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    cout<<"enter"<<endl;
    stack<pair<int,int>> st;
    int max =0;
    cout<<"size "<<h.size()<<endl;
    for(int i =0;i<h.size();i++){
        cout<<h[i]<<endl;
        int idx=i;
        while(!st.empty() && st.top().first>h[i]){
            cout<<"poping stack "<<st.top().first<<" "<<max<<endl;
            int num = (i - st.top().second)*(st.top().first);
            max = num>max?num:max;
            cout<<"New max "<<max<<endl;
            idx = st.top().second;
            st.pop();
        }
        st.push(make_pair(h[i],idx));
    }
    if(!st.empty()){
        int m = st.top().second;
        stack<pair<int,int>> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        while(!temp.empty()){
            cout<<"poping stack "<<temp.top().first<<" "<<max<<endl;
            int num = (m-temp.top().second +1)*(temp.top().first);
            max = num>max?num:max;
            cout<<"New max "<<max<<endl;
            temp.pop();
        }
    }
    cout<<"final ans "<<max<<endl;
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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
