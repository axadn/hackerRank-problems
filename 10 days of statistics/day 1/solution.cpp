#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


bool compare(const pair<int,int>& a, const pair<int,int>& b){
    if(a.second == b.second){
        return a.first > b.first;
     }else{
        return a.second < b.second; 
     }
}
int main() {
    int numsCount;
    int num;
    cin >> numsCount;
    vector<int> nums;
    int sum;
    unordered_map<int, int> counts;
    for(int i = 0; i < numsCount; ++i){
        cin >> num;
        nums.push_back(num);
        sum += num;
        push_heap(nums.begin(), nums.end());
        if(counts.count(num) == 0){
            counts[num] = 1;
        }
        else ++counts[num];
    }
    sort_heap(nums.begin(), nums.end());
    cout << float(sum) / numsCount << "\n";
    if(numsCount % 2 == 0){
        cout << float(nums[numsCount /2 - 1] + nums[numsCount / 2]) / 2 << "\n";
    }
    else{
        cout << nums[numsCount /2];
    }
    
    vector<pair<int, int>> counts2;
    for(unordered_map<int,int>::iterator it = counts.begin(); it != counts.end(); ++it){
        counts2.push_back(*it);
    }
    sort(counts2.begin(), counts2.end(), compare);
    cout << counts2[counts2.size() - 1].first;
}