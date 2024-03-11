#include <bits/stdc++.h>
using namespace std;

// 邻接矩阵
namespace adjacency_matrix{
#define MaxVertexNum 100
typedef struct {
    char Ver[MaxVertexNum]; // 顶点表
    int Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵，边表
    int vertexNum, edgeNum; // 顶点数和边/弧数
}MGraph;

}

// 邻接表
namespace adjacency_table {
typedef struct ArcNode {
    int adjvex; // 该弧所指向的顶点的位置
    struct ArcNode *next; // 指向下一条弧的指针
    int info; // 网的边权值
}ArcNode;

// 顶点类型
typedef struct VNode {
    int data; // 顶点信息
    ArcNode *first; // 指向第一条依附该顶点的弧的指针
}VNode, AdjList[MaxVertexNum];
}