#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> front;
    for(int i =0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            front.push(s[i]);
        }else{
            if(front.empty())
                return "NO";
            char ch = front.top();
            switch(ch){
                case '(':
                    if(s[i]==')')
                        front.pop();
                    else
                        return "NO";
                    break;
                case '{':
                    if(s[i]=='}')
                        front.pop();
                    else   
                        return "NO";
                    break;
                case '[':
                    if(s[i]==']')
                        front.pop();
                    else 
                        return "NO";
                    break;
            }
        }
    }
    return front.empty()?"YES":"NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
