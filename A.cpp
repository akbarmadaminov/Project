#include <bits/stdc++.h>
 
#define fr first
#define sc second
#define mk make_pair
#define pb push_back
#define ll long long
#define OK puts("OK");
#define sz(s) (int) s.size()
#define all(s) s.begin(), s.end()
 
using namespace std;
 
const int N = 1e5+10;
const int inf = 1e9+10;
const int linf = 1e18+9;
 
inline int min(int a, int b) {
    return (a > b) ? b : a;
}
 
int n, m, timer, root;
int mn[N], d[N], s[N], tin[N], tout[N], up[N][18], p[N];
bool u[N];
vector <vector <int> > g;
 
void dfs(int v, int p) {
    s[v] = 1;
    tin[v] = ++timer;
    up[v][0] = p;
    for(int i = 1; i <= 17; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for(int i = 0; i < sz(g[v]); i++) {
        int to = g[v][i];
        if(to == p) continue;
        d[to] = d[v] + 1;
        dfs(to, v);
        s[v] += s[to];
    }
    tout[v] = ++timer;
}
 
inline bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}
 
inline int lca(int a, int b) {
    if(upper(a, b)) return a;
    if(upper(b, a)) return b;
    for(int i = 17; i >= 0; i--) {
        if(!upper(up[a][i], b))
            a = up[a][i];
    }
    return up[a][0];
}
 
void Dfs(int v, int p) {
    s[v] = 1;
    for(int to : g[v])
        if(!u[to] && to != p)
            Dfs(to, v), s[v] += s[to];
}
 
void build(int v, int par, int lc, int ou) {
    bool fl = 1;
    for(int i = 0; i < sz(g[v]); i++) { int to = g[v][i];
        if(u[to] || to == par) continue;
        if(s[to] > ou / 2)
            fl = 0, build(to, v, lc, ou);
    }
    if(fl) {
        u[v] = 1;
        if(lc == 0) root = v;
        else
            p[v] = lc;
        for(int i = 0; i < sz(g[v]); i++) { int to = g[v][i];
            if(u[to]) continue;
            Dfs(to, to);
            build(to, to, v, s[to]);
        }
    }
}
 
inline int dist(int a, int b) {
    return d[a] + d[b] - 2 * d[lca(a, b)];
}
 
inline void UP(int v) {
    int cur = v;
    while(1) {
        mn[cur] = min(mn[cur], dist(cur, v));
        if(cur == root) break;
        cur = p[cur];
    }
}
 
inline int get(int v) {
    int res = inf, cur = v;
    while(1) {
        res = min(res, mn[cur] + dist(cur, v));
        if(cur == root) break;
        cur = p[cur];
    }
    return res;
}
 
int main() {
    scanf("%d%d", &n, &m);
    g.resize(n + 1);
    for(int i = 1, x, y; i < n; i++) {
        scanf("%d%d", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
        mn[i] = inf;
    }
    mn[n] = inf;
    dfs(1, 1);
    build(1, 1, 0, s[1]);
    UP(1);
    while(m--) {
        int type, v;
        scanf("%d%d", &type, &v);
        if(type == 1)
            UP(v);
        else
            printf("%d\n", get(v));
    }
}
