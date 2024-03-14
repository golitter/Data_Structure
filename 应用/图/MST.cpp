#include <bits/stdc++.h>
using namespace std;

namespace Prim {
    // https://www.luogu.com.cn/record/150835792
const int N = 5e3 + 21;
const int INF = 0x3f3f3f3f;
int g[N][N], dis[N], vis[N];

void solve() {
    memset(dis, 0x3f, sizeof(dis));
    int n,m; cin>>n>>m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            g[i][j] = (i == j ? 0 : INF);
        }
    }
    for(int i = 0, u,v,x; i < m; ++i) {
        cin>>u>>v>>x;
        g[u][v] = g[v][u] = min(g[u][v], x);
    }
    int val = 0;
    for(int k = 0; k < n; ++k) {
        int t = -1;
        for(int i = 1; i <= n; ++i) {
            if(!vis[i] && (t == -1 || dis[i] < dis[t])) {
                t = i;
            }
        }
        if(k && dis[t] == INF) {
            val = INF;
            break;
        }
        if(k) val += dis[t];
        for(int i = 1; i <= n; ++i) dis[i] = min(dis[i], g[t][i]);
        vis[t] = 1;
    }
    if(INF == val) cout<<"orz";
    else cout<<val;
}
}

namespace Kruskal {
    // https://www.luogu.com.cn/record/150838167
const int N = 2e5 + 21;
int fa[N];
int find(int p) {return p == fa[p] ? p : fa[p] = find(fa[p]); }
struct Edge {
    int u,v,w;
    bool operator<(const Edge &rhs) const {
        return w < rhs.w;
    }
}a[N];

void solve() {
    int n,m; cin>>n>>m;
    iota(fa, fa + n + 1, 0);
    for(int i = 0; i < m; ++i) {
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a, a + m);
    int val = 0, cnt = 0;
    for(int i = 0; i < m; ++i) {
        int u = find(a[i].u), v = find(a[i].v), w = a[i].w;
        if(u != v) {
            fa[u] = v;
            val += w;
            ++cnt;
        }
    }
    if(cnt < n - 1) cout<<"orz";
    else cout<<val;
}
}
int main()
{
    // Prim::solve();
    Kruskal::solve();
    return 0;
}