#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    int height1 = 0;
    for(int h1_i = n1 - 1;h1_i >= 0;h1_i--){
       cin >> h1[h1_i];
        height1 += h1[h1_i];
    }
    vector<int> h2(n2);
    int height2 = 0;
    for(int h2_i = n2 - 1;h2_i >= 0;h2_i--){
       cin >> h2[h2_i];
        height2 += h2[h2_i];
    }
    vector<int> h3(n3);
    int height3 = 0;
    for(int h3_i = n3 - 1;h3_i >= 0;h3_i--){
       cin >> h3[h3_i];
       height3 += h3[h3_i];
    }
    vector<vector<int>> stacks;
    vector<int> heights;
    heights.push_back(height1);
    heights.push_back(height2);
    heights.push_back(height3);
    stacks.push_back(h1);
    stacks.push_back(h2);
    stacks.push_back(h3);

    int maxStack = 0;
    int maxHeight = 0;
    while(!(heights[0]== heights[1] && heights[1] == heights[2])){
        maxHeight = 0;
        for(int i = 0; i < stacks.size(); ++i){
            if(heights[i] > maxHeight){
                maxHeight = heights[i];
                maxStack = i;
            }
        }
        heights[maxStack] -= stacks[maxStack].back();

        stacks[maxStack].pop_back();
    }
    cout << heights[maxStack];
}
