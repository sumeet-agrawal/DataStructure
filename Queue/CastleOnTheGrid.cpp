#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    vector<vector<int>> visited;
    for(int i=0;i<grid.size();i++){
        vector<int> temp(grid.size(),0);
        visited.push_back(temp);
    }
    vector<vector<int>> bfs;
    vector<int> arr{startX,startY,0};
    bfs.push_back(arr);
    visited[startX][startY]=1;
    int i=0;
    while(i<bfs.size()){
        for(int j=bfs[i][0]+1;j<grid.size();j++){
            if(!visited[j][bfs[i][1]]){
                if(grid[j][bfs[i][1]]=='.'){
                    vector<int> t{j,bfs[i][1],bfs[i][2]+1};
                    bfs.push_back(t);
                    visited[j][bfs[i][1]]=1;
                    if(j==goalX && bfs[i][1]==goalY){
                        return bfs[i][2]+1;
                    }
                }else{
                    break;
                }
            }
        }
        for(int j=bfs[i][1]+1;j<grid.size();j++){
            if(!visited[bfs[i][0]][j]){
                if(grid[bfs[i][0]][j]=='.'){
                    vector<int> t{bfs[i][0],j,bfs[i][2]+1};
                    bfs.push_back(t);
                    visited[bfs[i][0]][j]=1;
                    if(bfs[i][0]==goalX && j==goalY){
                        return bfs[i][2]+1;
                    }
                }else{
                    break;
                }
            }
        }
        for(int j=bfs[i][0]-1;j>=0;j--){
            if(!visited[j][bfs[i][1]]){
                if(grid[j][bfs[i][1]]=='.'){
                    vector<int> t{j,bfs[i][1],bfs[i][2]+1};
                    bfs.push_back(t);
                    visited[j][bfs[i][1]]=1;
                    if(j==goalX && bfs[i][1]==goalY){
                        return bfs[i][2]+1;
                    }
                }else{
                    break;
                }
            }
        }
        for(int j=bfs[i][1]-1;j>=0;j--){
            if(!visited[bfs[i][0]][j]){
                if(grid[bfs[i][0]][j]=='.'){
                    vector<int> t{bfs[i][0],j,bfs[i][2]+1};
                    bfs.push_back(t);
                    visited[bfs[i][0]][j]=1;
                    if(bfs[i][0]==goalX && j==goalY){
                        return bfs[i][2]+1;
                    }
                }else{
                    break;
                }
            }
        }
        i++;
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

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
