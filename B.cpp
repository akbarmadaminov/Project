#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 3e5+10;
const int inf = 1e9+7;
 
int n, k, q;
char a[N], c;
int t[4*N];
 
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = 1;
    } else {
        int tm = (tl + tr) / 2;
        build(v + v, tm + 1, tr);
        build(v + v + 1, tl, tm);
        if (a[v] == '1') t[v] = t[v + v];
        if (a[v] == '0') t[v] = t[v + v + 1];
        if (a[v] == '?') t[v] = t[v + v + 1] + t[v + v];
    }
}
 
void upd(int p, char c) {
    a[n - p] = c;
    int v = n - p;
    while (v > 0) {
        if (a[v] == '1') t[v] = t[v + v];
        if (a[v] == '0') t[v] = t[v + v + 1];
        if (a[v] == '?') t[v] = t[v + v + 1] + t[v + v];
        v >>= 1;
    }
}
 
int main() {
    cin >> k;
    n = (1 << k);
    for (int i = 1; i < n; i++)
        cin >> a[i];
    reverse(a + 1, a + n);
    build(1, 1, n);
    cin >> q;
    while (q--) {
        int p;
        cin >> p >> c;
        upd(p, c);
        cout << t[1] << endl;
    }
    return 0;
}
