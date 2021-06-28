#include <bits/stdc++.h>
 
#define fr first
#define sc second
#define mk make_pair
#define pb push_back
#define ll long long
#define OK puts("OK")
#define sz(s) (int)s.size()
#define all(s) s.begin(), s.end()
 
using namespace std;
 
const int N = 2010;
const int inf = 1e9+7;
 
int n, cnt, u[N];
int a[N], b[N][N];
vector <pair <int, int> > ans;
 
void go(int v, int p, int pp) {
    ++cnt;
    cout << "? " << v << endl;
 
    vector <int> cur[N];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cur[a[i]].pb(i);
    }
    int A = 0, B = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0)
            A += sz(cur[i]);
        else
            B += sz(cur[i]);
    }
    if (A > B) {
        for (int i = 1; i <= n; i += 2) {
            for (auto j : cur[i]) {
                cout << "? " << j << endl;
                for (int k = 1; k <= n; k++) {
                    cin >> b[j][k];
                    if (b[j][k] == 1)
                        ans.pb(mk(j, k));
                }
            }
        }
    } else {
        for (int i = 2; i <= n; i += 2) {
            for (auto j : cur[i]) {
                cout << "? " << j << endl;
                for (int k = 1; k <= n; k++) {
                    cin >> b[j][k];
                    if (b[j][k] == 1)
                        ans.pb(mk(j, k));
                }
            }
        }
        for (auto i : cur[1])
            ans.pb(mk(i, 1));
    }
}
 
void solve() {
    cin >> n;
    go(1, 0, 0);
    puts("!");
    for (auto i : ans)
        cout << i.fr << " " << i.sc << endl;
}
 
int main() {
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
}
