/**
Given a string of lowercase letters in the range ascii[a-z], determine a character that can be removed to make the string a palindrome. There may be more than one solution, but any will do. For example, if your string is "bcbc", you can either remove 'b' at index  or 'c' at index . If the word is already a palindrome or there is no solution, return -1. Otherwise, return the index of a character to remove.

Input Format

The first line contains an integer , the number of queries. 
Each of the next  lines contains a query string .

Constraints

All characters are in the range ascii[a-z].
Output Format

Print an integer denoting the zero-indexed position of the character to remove to make  a palindrome. If  is already a palindrome or no such character exists, print .

Sample Input

3
aaab
baa
aaa
Sample Output

3
0
-1
Explanation

Query 1: "aaab" 
Removing 'b' at index  results in a palindrome, so we print  on a new line.

Query 2: "baa" 
Removing 'b' at index  results in a palindrome, so we print  on a new line.

Query 3: "aaa" 
This string is already a palindrome, so we print . Removing any one of the characters would result in a palindrome, but this test comes first.
**/
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string& s, int startIdx, int endIdx){
    while(startIdx < endIdx){
        if(s[startIdx++] != s[endIdx--]){
            return false;
        }
    }
    return true;
}

int palindromeIndex(string s){
    int front = 0;
    int back = s.size() - 1;
    bool removed = 0;
    while(front < back){
        if(s[front] == s[back]){
            ++front;
            --back;
        }
        else{
            if(isPalindrome(s, front, back - 1)){
                return back;
            }
            else if(isPalindrome(s, front + 1, back)){
                return front;
            }
            else{
                return -1;
            }
        }
    }
    return -1;
}


int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = palindromeIndex(s);
        cout << result << endl;
    }
    return 0;
}
