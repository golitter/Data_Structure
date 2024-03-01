#include <bits/stdc++.h>
using namespace std;

const int MaxSize = 50;
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

bool initQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
    return true;
}

bool isEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

bool EnQueue(SqQueue &Q, ElemType e) {
    if( (Q.rear + 1) % MaxSize == Q.front) {
        return false;
    }
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &e) {
    if(Q.rear == Q.front) {
        return false;
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

bool GetHead(SqQueue Q, ElemType &e) {
    if(Q.rear == Q.front) {
        return false;
    }
    e = Q.data[Q.front];
    return true;
}


// void solve() {
//     SqQueue Q;
//     initQueue(Q);
//     for(int i = 0; i < 10; ++i) {
//         EnQueue(Q, i);
//     }
//     while(!isEmpty(Q)) {
//         int e;
//         DeQueue(Q, e);
//         cout<<e<<' ';
//     }
//     cout<<endl;
    
// }