#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    vector<vector<int>> vec(4);
    int max = INT_MIN;
    for(int j=0;j<4;j++){
        vec[j].resize(4);
        for(int k =0;k<4;k++){
            vec[j][k]=arr[j][k]+arr[j][k+1]+arr[j][k+2]+arr[j+1][k+1]+arr[j+2][k]+arr[j+2][k+1]+arr[j+2][k+2];
            if(vec[j][k]>max)
                max = vec[j][k];
        }
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
