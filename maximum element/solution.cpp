#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    int numQueries;
    cin >> numQueries;
    int param1;
    int param2;
    int max;
    std::stack<std::pair<int,int>> stack;
    while(numQueries > 0){
        cin >> param1;
        if(param1 == 1){
            cin >> param2;
            if(stack.empty()){
                max = param2;
            }
            else{
                max = std::max(stack.top().second, param2);
            }
            stack.push(std::make_pair(param2, max));
        }
        else if (param1 == 3){
            if(stack.empty()){
                max = 0;
            }
            else{
                max = stack.top().second;
            }
            cout << max << "\n";
        }
        else if (param1 == 2){
            if(!stack.empty()) stack.pop();
        }
        --numQueries;
    }
    return 0;
}
