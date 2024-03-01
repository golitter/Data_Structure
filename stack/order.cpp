#include <bits/stdc++.h>
using namespace std;
const int MaxSize = 50;
typedef int ElemType;

typedef struct SqStack {
    ElemType data[MaxSize];
    int top;
}SqStack;

bool initStack(SqStack &S) {
    S.top = -1;
    return true;
}

bool stackEmpty(SqStack S) {
    return S.top == -1;
}

bool Push(SqStack &S, ElemType x) {
    if(S.top == MaxSize - 1) {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &e) {
    if(S.top == -1) {
        return false;
    }
    e = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, ElemType &e) {
    if(S.top == -1) {
        return false;
    }
    e = S.data[S.top];
    return true;
}

