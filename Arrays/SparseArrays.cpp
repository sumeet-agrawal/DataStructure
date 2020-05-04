#include <bits/stdc++.h>

using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    map<string, int> hash;
    for(int i =0;i<queries.size();i++){
        auto it = hash.find(queries[i]);
        if(it==hash.end()){
            hash.insert(make_pair(queries[i],0));
        }
    }
    for(int i =0;i<strings.size();i++){
        auto it = hash.find(strings[i]);
        if(it!=hash.end()){
            it->second++;
        }
    }
    vector<int> arr;
    for(int i=0;i<queries.size();i++){
        auto it = hash.find(queries[i]);
        if(it!=hash.end()){
            arr.push_back(it->second);
        }
        else{
            arr.push_back(0);
        }
    }
    return arr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int strings_count;
    cin >> strings_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(strings, queries);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
