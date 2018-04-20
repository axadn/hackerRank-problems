#include <bits/stdc++.h>

using namespace std;

void bucketSort(string& w, int start){
    unordered_map<char, int> letterCounts;
    
    for(int i = start; i < w.size(); ++i){
        if(letterCounts.find(w[i]) != letterCounts.end()){
            letterCounts[w[i]] += 1;
        }
        else{
            letterCounts[w[i]] = 1;
        }
    }
    
    int currentIndex = start;
    int repeatTimes;
    for(int i = 0; i < 26; ++i){
        if(letterCounts.find('a' + i)!= letterCounts.end()){
            repeatTimes = letterCounts['a' + i];
            for(int j = 0; j < repeatTimes; ++j){
                w[currentIndex] = 'a' + i;
                ++currentIndex;
            }
        }
    }
}

string biggerIsGreater(string w) {
    char tmp;
    int swapIdx;
    for(int i =  w.size() - 2; i >= 0; i --){
        if(w[i] < w[i + 1]){
            swapIdx = i + 1;
            while(w[swapIdx + 1] > w[i] && swapIdx + 1 < w.size()){
                ++swapIdx;
            }
            tmp = w[swapIdx];
            w[swapIdx] = w[i];
            w[i] = tmp;
            bucketSort(w, i + 1);
            return w;
        }
    }
    return "no answer";
}

int main() {
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        string w;
        cin >> w;
        string result = biggerIsGreater(w);
        cout << result << endl;
    }
    return 0;
}