#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the twoStacks function below.
 */
int twoStacks(int x, vector<int> a, vector<int> b) {
    /*vector<vector<int>> bfs;
    int idx=-1;
    if(a[0]<=x){
        vector<int> arr={a[0],0,-1};
        bfs.push_back(arr);
    }
    if(b[0]<=x){
        vector<int> brr={b[0],-1,0};
        bfs.push_back(brr);
    }
    while(1){
        idx++;
        cout<<idx<<" "<<bfs.size()<<endl;
        if(idx>=bfs.size())
            break;
        cout<<bfs[idx][0]<<" "<<bfs[idx][1]<<" "<<bfs[idx][2]<<endl;
        if(bfs[idx][1]+1<a.size()){
            if(bfs[idx][0]+a[bfs[idx][1]+1]<=x){
                vector<int> t1 = {bfs[idx][0]+a[bfs[idx][1]+1],bfs[idx][1]+1,bfs[idx][2]};
                bfs.push_back(t1);
            }
        }
        if(bfs[idx][2]+1<b.size()){
            if(bfs[idx][0]+b[bfs[idx][2]+1]<=x){
                vector<int> t2 = {bfs[idx][0]+b[bfs[idx][2]+1],bfs[idx][1],bfs[idx][2]+1};
                bfs.push_back(t2);
            }
        }
    }
    if(bfs.size())
        return bfs[bfs.size()-1][1]+bfs[bfs.size()-1][2] +2; 
    return 0;
    */
    int i=0,j=0,count=0,sum=0;
    while(i<a.size() && (sum+a[i])<=x){
        sum+=a[i];
        i++;
    }
    count = i;
    while(j<b.size()){
        sum+=b[j];
        j++;
        while(sum>x && i>0){
            i--;
            sum-=a[i];
        }
        if(sum<=x && i+j>count){
            count = i+j;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string nmx_temp;
        getline(cin, nmx_temp);

        vector<string> nmx = split_string(nmx_temp);

        int n = stoi(nmx[0]);

        int m = stoi(nmx[1]);

        int x = stoi(nmx[2]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<int> a(n);

        for (int a_itr = 0; a_itr < n; a_itr++) {
            int a_item = stoi(a_temp[a_itr]);

            a[a_itr] = a_item;
        }

        string b_temp_temp;
        getline(cin, b_temp_temp);

        vector<string> b_temp = split_string(b_temp_temp);

        vector<int> b(m);

        for (int b_itr = 0; b_itr < m; b_itr++) {
            int b_item = stoi(b_temp[b_itr]);

            b[b_itr] = b_item;
        }

        int result = twoStacks(x, a, b);

        fout << result << "\n";
    }

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
