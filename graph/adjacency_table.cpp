#include <bits/stdc++.h>
#include "./definition.cpp"
using namespace std;
using namespace adjacency_table;

// 判断G是否存在边{u,v }
bool Adjacent(AdjList G, int u, int v) {
    ArcNode *p = G[u].first;
    while (p) {
        if (p->adjvex == v) {
            return true;
        }
        p = p->next;
    }
    return false;
}

// 列出顶点v的所有邻接点
void Neighbors(AdjList G, int v) {
    ArcNode *p = G[v].first;
    while (p) {
        cout << G[p->adjvex].data << " ";
        p = p->next;
    }
    cout << endl;
}

// 在G中插入顶点v
void InsertVertex(AdjList &G, char v) {
    G[G[0].data].data = v;
    G[0].data++;
}

// 在G中插入边{u,v}
void InsertEdge(AdjList &G, int u, int v) {
    ArcNode *p = new ArcNode;
    p->adjvex = v;
    p->next = G[u].first;
    G[u].first = p;
    p = new ArcNode;
    p->adjvex = u;
    p->next = G[v].first;
    G[v].first = p;
}

// 在G中删除顶点v
void DeleteVertex(AdjList &G, char v) {
    int i = 1;
    for (; i <= G[0].data; i++) {
        if (G[i].data == v) {
            break;
        }
    }
    if (i > G[0].data) {
        return;
    }
    for (int j = 1; j <= G[0].data; j++) {
        ArcNode *p = G[j].first;
        while (p) {
            if (p->adjvex == i) {
                ArcNode *q = p;
                p = p->next;
                delete q;
            } else {
                p = p->next;
            }
        }
    }
    for (int j = i; j < G[0].data; j++) {
        G[j] = G[j + 1];
    }
    G[0].data--;
}

// 在G中删除边{u,v}
void DeleteEdge(AdjList &G, int u, int v) {
    ArcNode *p = G[u].first;
    if (p->adjvex == v) {
        G[u].first = p->next;
        delete p;
    } else {
        while (p->next) {
            if (p->next->adjvex == v) {
                ArcNode *q = p->next;
                p->next = q->next;
                delete q;
                break;
            }
            p = p->next;
        }
    }
    p = G[v].first;
    if (p->adjvex == u) {
        G[v].first = p->next;
        delete p;
    } else {
        while (p->next) {
            if (p->next->adjvex == u) {
                ArcNode *q = p->next;
                p->next = q->next;
                delete q;
                break;
            }
            p = p->next;
        }
    }
}

int main() {
    AdjList G;
    G[0].data = 0;
    InsertVertex(G, 'A');
    InsertVertex(G, 'B');
    InsertVertex(G, 'C');
    InsertVertex(G, 'D');
    InsertEdge(G, 1, 2);
    InsertEdge(G, 1, 3);
    InsertEdge(G, 1, 4);
    InsertEdge(G, 2, 3);
    InsertEdge(G, 2, 4);
    InsertEdge(G, 3, 4);
    cout << Adjacent(G, 1, 2) << endl;
    Neighbors(G, 1);
    DeleteEdge(G, 1, 2);
    Neighbors(G, 1);
    DeleteVertex(G, 'A');
    Neighbors(G, 2);
    return 0;
}