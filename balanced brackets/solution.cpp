#include <bits/stdc++.h>
#include <stack>
#include <unordered_map>

using namespace std;

string isBalanced(string const& s, unordered_map<char,char> const& bracketMap) {
    std::stack<char> stack;
    for(int i = 0; i < s.length(); ++i){
        if(bracketMap.find(s[i]) == bracketMap.end()){
            stack.push(s[i]);
        }
        else if(stack.empty()){
            return "NO";
        }
        else if(bracketMap.find(s[i])->second == stack.top()){
            stack.pop();
        }
        else{
            return "NO";
        }
    }
    return(stack.empty()) ? "YES" : "NO";
}

int main() {
    int t;
    cin >> t;
    std::unordered_map<char, char> bracketMap;
    bracketMap[')'] = '(';
    bracketMap[']'] = '[';
    bracketMap['}'] = '{';
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        string result = isBalanced(s, bracketMap);
        cout << result << endl;
    }
    return 0;
}
