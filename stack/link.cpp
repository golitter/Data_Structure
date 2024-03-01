#include <bits/stdc++.h>
using namespace std;
typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
}*LinkStack, LinkNode;

bool initStack(LinkStack &S) {
    S = NULL;
    return true;
}

bool stackEmpty(LinkStack S) {
    return S == NULL;
}

bool Push(LinkStack &S, ElemType e) {
    LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = e;
    p->next = S;
    S = p;
    return true;
}

bool Pop(LinkStack &S, ElemType &e) {
    if(S == NULL) {
        return false;
    }
    LinkNode *p = S;
    e = p->data;
    S = S->next;
    free(p);
    return true;
}

bool GetTop(LinkStack S, ElemType &e) {
    if(S == NULL) {
        return false;
    }
    e = S->data;
    return true;
}