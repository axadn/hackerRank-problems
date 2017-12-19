/*
by only marking the difference between successive elements,
at the start and end index of each update,
updates can be done in constant time.
Therefore, this solution allows for a final time complexity of O(m + n),
where m is the number of updates and n the size of the array
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    long *arr = new long[n];
    for(int a0 = 0; a0 < m; a0++){
        int a;
        int b;
        int k;
        cin >> a >> b >> k;
        arr[a - 1] += k;
        if(b < n) arr[b] -= k;
    }
    long sum = arr[0];
    long max = sum;
    for(int i = 1; i < n; ++i){
        sum += arr[i];
        if(sum > max){
            max = sum;
        }
    }
    cout << max;
    return 0;
}
