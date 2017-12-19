#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {

    std::string line;
    int lineCount = 0;

    getline(cin, line);
    stringstream lineCountStream(line);
    lineCountStream >> lineCount;

    std::unordered_map<std::string, int> stringCounts;
    for(int i = 0; i < lineCount; ++i){
        getline(cin, line);
        ++stringCounts[line];
    }

    getline(cin, line);
    lineCountStream = stringstream(line);
    lineCountStream >> lineCount;

    for(int i = 0; i < lineCount; ++i){
        getline(cin, line);
        cout << stringCounts[line] << '\n';
    }

    return 0;
}
