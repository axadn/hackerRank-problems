#include <bits/stdc++.h>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

string isValid(string s){
    std::unordered_map<char, int> countmap;
    for(int i = 0; i < s.length(); ++i ){
        if(countmap.count(s[i])==0){
            countmap[s[i]] = 1;
        }
        else{
            ++countmap[s[i]];
        }
    }
    std::unordered_map<int, int> frequencyCounts;
    for(std::unordered_map<char, int>::iterator it = countmap.begin(); it != countmap.end(); ++it){
        if(frequencyCounts.count(it->second) == 0){
            frequencyCounts[it->second] = 1;
        }
        else{
            ++frequencyCounts[it->second];
        }
    }
    if(frequencyCounts.size() > 2 ){
        return "NO";
    }
    else if(frequencyCounts.size() == 2){
        std::unordered_map<int, int>::iterator it = frequencyCounts.begin();
        int freq1 = it->first;
        int freqCount1 = it->second;
        ++it;
        int freqCount2 = it->second;
        int freq2 = it->first;
        if(freqCount1 == 1 && freq1 ==1 || freqCount2 == 1 && freq2 == 1) return "YES";
        if(freq1 > freq2){
           if(freq1 == freq2 + 1 &&
              freqCount1 == 1){
               return "YES";
           }
            return "NO";
        }
        else{
            if(freq2 == freq1 +1 &&
               freqCount2 ==1){
                return "YES";
            }
            return "NO";
        }
    }
    return "YES";
}

int main() {
    string s;
    cin >> s;
    string result = isValid(s);
    cout << result << endl;
    return 0;
}
