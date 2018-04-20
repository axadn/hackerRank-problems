#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    
    int length;
    int val;
    int valueSum = 0;
    int weightSum = 0;
    vector<int> values;
    cin >> length;
    for(int i = 0; i < length; ++i){
        cin >>val;
        values.push_back(val);
    }
    for(int i = 0; i < length; ++i){
        cin >>val;
        weightSum += val;
        valueSum += val * values[i]; 
    }
    cout << fixed << setprecision(1) << float(valueSum ) / float(weightSum);
    return 0;
}
