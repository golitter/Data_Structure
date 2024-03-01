#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;

typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct {
    LinkNode *front,*rear;
}LinkQueue;

bool initQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
    return true;
}

bool isEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

bool EnQueue(LinkQueue &Q, ElemType e) {
    LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return true;
}

bool DeQueue(LinkQueue &Q, ElemType &e) {
    if(Q.front == Q.rear) {
        return false;
    }
    LinkNode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if(Q.rear == p) { // 只有一个结点时
        Q.rear = Q.front;
    }
    return true;
}

bool GetHead(LinkQueue Q, ElemType &e) {
    if(Q.front == Q.rear) {
        return false;
    }
    e = Q.front->next->data;
    return true;
}