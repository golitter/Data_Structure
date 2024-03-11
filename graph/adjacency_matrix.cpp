#include <bits/stdc++.h>
#include "./definition.cpp"
using namespace std;
using namespace adjacency_matrix;

// 判断G是否存在边{u,v }
bool Adjacent(MGraph G, int u, int v) {
    return G.Edge[u][v] != 0;
}

// 列出顶点v的所有邻接点
void Neighbors(MGraph G, int v) {
    for (int i = 0; i < G.vertexNum; i++) {
        if (G.Edge[v][i] != 0) {
            cout << G.Ver[i] << " ";
        }
    }
    cout << endl;
}
// 在G中插入顶点v
void InsertVertex(MGraph &G, char v) {
    G.Ver[G.vertexNum++] = v;
}

// 在G中插入边{u,v}
void InsertEdge(MGraph &G, int u, int v) {
    G.Edge[u][v] = 1;
    G.Edge[v][u] = 1;
    G.edgeNum++;
}

// 在G中删除顶点v
void DeleteVertex(MGraph &G, char v) {
    int i = 0;
    for (; i < G.vertexNum; i++) {
        if (G.Ver[i] == v) {
            break;
        }
    }
    if (i == G.vertexNum) {
        return;
    }
    for (int j = i; j < G.vertexNum - 1; j++) {
        G.Ver[j] = G.Ver[j + 1];
    }
    for (int j = 0; j < G.vertexNum; j++) {
        for (int k = i; k < G.vertexNum - 1; k++) {
            G.Edge[j][k] = G.Edge[j][k + 1];
        }
    }
    for (int j = 0; j < G.vertexNum; j++) {
        for (int k = i; k < G.vertexNum - 1; k++) {
            G.Edge[k][j] = G.Edge[k + 1][j];
        }
    }
    G.vertexNum--;
}

// 在G中删除边{u,v}
void DeleteEdge(MGraph &G, int u, int v) {
    G.Edge[u][v] = 0;
    G.Edge[v][u] = 0;
    G.edgeNum--;
}

int main() {
    MGraph G;
    G.vertexNum = 0;
    G.edgeNum = 0;
    InsertVertex(G, 'A');
    InsertVertex(G, 'B');
    InsertVertex(G, 'C');
    InsertVertex(G, 'D');
    InsertEdge(G, 0, 1);
    InsertEdge(G, 0, 2);
    InsertEdge(G, 0, 3);
    InsertEdge(G, 1, 2);
    InsertEdge(G, 1, 3);
    InsertEdge(G, 2, 3);
    cout << "邻接矩阵：" << endl;
    for (int i = 0; i < G.vertexNum; i++) {
        for (int j = 0; j < G.vertexNum; j++) {
            cout << G.Edge[i][j] << " ";
        }
        cout << endl;
    }
    cout << "顶点表：" << endl;
    for (int i = 0; i < G.vertexNum; i++) {
        cout << G.Ver[i] << " ";
    }
    cout << endl;
    cout << "顶点A的邻接点：" << endl;
    Neighbors(G, 0);
    cout << "删除边{A,B}：" << endl;
    DeleteEdge(G, 0, 1);
    for (int i = 0; i < G.vertexNum; i++) {
        for (int j = 0; j < G.vertexNum; j++) {
            cout << G.Edge[i][j] << " ";
        }
        cout << endl;
    }
    cout << "删除顶点A：" << endl;
    DeleteVertex(G, 'A');
    for (int i = 0; i < G.vertexNum; i++) {
        cout << G.Ver[i] << " ";
    }
    cout << endl;
    return 0;
}
