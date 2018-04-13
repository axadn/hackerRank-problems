#include <bits/stdc++.h>
/** O(n) solution **/
using namespace std;
inline int calculateMax(vector<int> const& a, vector<int> const& b, int maxSum);
int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        int m;
        int x;
        cin >> n >> m >> x;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        vector<int> b(m);
        for(int b_i = 0; b_i < m; b_i++){
           cin >> b[b_i];
        }
        cout << calculateMax(a, b, x) << "\n";
    }
    return 0;
}

inline int calculateMax(vector<int> const& a, vector<int> const& b, int maxSum){
    int maxPops = 0;
    int leftSum = 0;
    int leftPops = 0;

    while(leftSum <= maxSum && leftPops <= a.size()){
        leftSum += a[leftPops++];
    }
    leftSum -= a[--leftPops];

    int rightSum = 0;
    int rightPops = 0;
    while(leftPops >= 0){
        while(leftSum + rightSum <= maxSum && rightPops <= b.size()){
            rightSum += b[rightPops++];
        }
        rightSum -= b[--rightPops];

        maxPops = std::max(rightPops + leftPops, maxPops);

        if(leftPops > 0){
            leftSum -= a[leftPops - 1];
        }
        --leftPops;
    }
    return maxPops;
}
