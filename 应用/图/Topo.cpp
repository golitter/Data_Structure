    // https://www.luogu.com.cn/record/150841707
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 21;
int e[N], ne[N],h[N], idx, in[N];
void add(int u, int v) {
    e[idx] = v; ne[idx] = h[u]; h[u] = idx++;
}
void solve() {
    int n; cin>>n;
    memset(h, -1, sizeof(h));
    for(int i = 1, u; i <= n; ++i) {
        while(cin>>u, u) {
            add(i, u);
            in[u]++;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if(!in[i]) q.push(i);
    }
    while(q.size()) {
        auto t = q.front(); q.pop();
        cout<<t<<' ';
        for(int i = h[t]; ~i; i = ne[i]) {
            int y = e[i];
            in[y]--;
            if(!in[y]) q.push(y);
        }
    }
    
}
int main()
{
    solve(); return 0;
}