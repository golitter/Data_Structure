#include <bits/stdc++.h>
using namespace std;
#define MAX_VERTEX_NUM 20
bool vis[MAX_VERTEX_NUM];

// 图
vector<vector<int>> G(MAX_VERTEX_NUM);
void visit(int v) {
    cout << v << " ";
}
void bfs(int u) {
    visit(u);
    vis[u] = true;
    queue<int> q;
    q.push(u);
    while(q.size()) {
        auto v = q.front(); q.pop();
        for(auto &y: G[v]) {
            if(!vis[y]) {
                visit(y);
                vis[y] = true;
                q.push(y);
            }
        }
    }
}
void dfs(int u) {
    visit(u);
    vis[u] = true;
    for(auto &y: G[u]) {
        if(!vis[y]) {
            dfs(y);
        }
    }
}
int main()
{

}