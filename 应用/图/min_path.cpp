
// https://www.luogu.com.cn/record/150827536
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 21;
const int INF = 0x3f3f3f3f;
using PII = pair<int, int>;
int e[N], ne[N], w[N], h[N], idx, dis[N], vis[N];
void add(int u, int v, int c) {
    e[idx] = v, w[idx] = c, ne[idx] = h[u], h[u] = idx++;
}
void solve() {
    int n,m,s; cin>>n>>m>>s;
    memset(h, -1, sizeof(h));
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 0; i < m; ++i) {
        int u,v,x; cin>>u>>v>>x;
        add(u,v,x);
    }
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, s});
    dis[s] = 0;
    while(q.size()) {
        auto tmp = q.top(); q.pop();
        int v = tmp.second, d = tmp.first;
        if(vis[v]) continue;
        vis[v] = 1;
        for(int i = h[v]; ~i; i = ne[i]) {
            int y = e[i];
            if(dis[y] > dis[v] + w[i]) {
                dis[y] = dis[v] + w[i];
                q.push({dis[y], y});
            }
        }
    }
    for(int i = 1; i <= n; ++i) cout<<dis[i]<<' ';
}
int main()
{
    solve(); return 0;
}