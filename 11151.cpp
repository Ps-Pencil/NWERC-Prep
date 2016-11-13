//uVa 11151 Longest Palindrome
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int a[1002][1002];

int T,len;
string S;

int f(int l, int r) {
    if (a[l][r] != 0) return a[l][r];
    a[l][r] = S[l] == S[r] ? 2 + f(l + 1, r - 1) : max(f(l, r - 1), f(l + 1, r));
    return a[l][r];
}

int main() {
    cin >> T;
    cin.ignore();
    for (int c = 0; c < T; ++c) {
        getline(cin, S);
        memset(a, 0, sizeof(a));
        len = (int) S.length();
        if (len == 0) {cout << 0 << endl; continue;}
        for (int i = 0; i < len - 1; ++i) {
            a[i][i] = 1;
            a[i][i + 1] = S[i] == S[i + 1] ? 2 : 1;
        }
        a[len - 1][len - 1] = 1;
        cout << f(0, len - 1) << endl;
    }
}
