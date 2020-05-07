#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the componentsInGraph function below.
 */
vector<int> componentsInGraph(vector<vector<int>> gb) {
    cout<<gb.size()<<endl;
    vector<int> parent(2*gb.size()+1);
    vector<int> count(2*gb.size()+1);
    cout<<parent.size()<<" "<<count.size()<<endl;
    for(int i =0;i<gb.size();i++){
        cout<<gb[i][0]<<" "<<gb[i][1]<<" "<<parent[gb[i][0]]<<" "<<parent[gb[i][1]]<<endl;
        if(parent[gb[i][0]] == 0){
            if(parent[gb[i][1]] == 0){
                cout<<"Both zero"<<endl;
                parent[gb[i][1]] = gb[i][0];
                parent[gb[i][0]] = gb[i][0];
                count[gb[i][0]] = 2;
            }else{
                cout<<"0 zero"<<endl;
                parent[gb[i][0]] = parent[gb[i][1]];
                count[parent[gb[i][1]]]++;
            }
        }else{
            if(parent[gb[i][1]] == 0){
                cout<<"1 zero"<<endl;
                parent[gb[i][1]] = parent[gb[i][0]];
                count[parent[gb[i][0]]]++;
            }else{
                cout<<"Both non zero"<<endl;
                int dis = parent[gb[i][1]];
                for(int j=0;j<parent.size();j++){
                    if(parent[j]==dis){
                        parent[j]=parent[gb[i][0]];
                        count[dis]--;
                        count[parent[gb[i][0]]]++;
                    }
                }
                //parent[parent[gb[i][1]]] = parent[gb[i][0]];
                //count[parent[gb[i][1]]]--;
                //count[parent[gb[i][0]]]++;
            }
        }
    }
    vector<int> ans(2);
    cout<<parent.size()<<" "<<count.size()<<endl;
    ans[0] = 2*gb.size() +2;ans[1] = 0;
    for(int i=1;i<count.size();i++){
        cout<<count[i]<<" ";
        if(count[i]){
            ans[0] = count[i]<ans[0]?count[i]:ans[0];
            ans[1] = count[i]>ans[1]?count[i]:ans[1];
        }
    }
    cout<<endl;
    for(int i=1;i<parent.size();i++){
        cout<<parent[i]<<" ";
    }
    cout<<endl;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> gb(n);
    for (int gb_row_itr = 0; gb_row_itr < n; gb_row_itr++) {
        gb[gb_row_itr].resize(2);

        for (int gb_column_itr = 0; gb_column_itr < 2; gb_column_itr++) {
            cin >> gb[gb_row_itr][gb_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = componentsInGraph(gb);

    for (int SPACE_itr = 0; SPACE_itr < result.size(); SPACE_itr++) {
        fout << result[SPACE_itr];

        if (SPACE_itr != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
