#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
/**
 * 加上&符号：表示传递参数指针的引用，函数可以修改外部指针变量所指向的内容。
 * 不加&符号：表示传递指针的副本，函数内部对指针的修改不会影响到外部指针变量的指向。
*/

// 初始化链表
bool initList(LinkList &L) {
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    return true;
}

// 求表长
int Length(LinkList L) {
    LNode *p = L;
    int sz = 0;
    while(p->next != NULL) {
        sz++;
        p = p->next;
    }
    return sz;
}

// 插入
bool listInsert(LinkList &L, int i, ElemType e) {
    int j = 0;
    LNode *p = L;
    while(p != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    if(p == NULL) {
        return false;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 在p结点后插入
bool listInsertAfter(LNode *p, ElemType e) {
    LNode *q = p->next;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = q;
    p->next = s;
    ElemType temp = s->data;
    s->data = p->data;
    p->data = temp;
    return true;
}

// 删除
bool listDelete(LinkList &L, int i, ElemType &e) {
    LNode *p = L;
    int j = 0;
    while(p != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    if(p == NULL || p->next == NULL) {
        return false;
    }
    LNode *q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
}

// 头插法
void listHeaderInsert(LinkList &L) {
    initList(L);
    int inp; scanf("%d", &inp);
    while(inp != 114514) {
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = inp;
        s->next = L->next;
        L->next = s;
        scanf("%d", &inp);
    }
}

// 尾插法
void listTailerInsert(LinkList &L) {
    initList(L);
    LNode *r = L;
    int inp; scanf("%d", &inp);
    while(inp != 114514) {
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = inp;
        r->next = s;
        r = s;
        scanf("%d", &inp);
    }
    r->next = NULL;
}

// 展示
void Display(LinkList L) {
    LNode *p = L;
    while(p->next != NULL) {
        p = p->next;
        printf("%d  ", p->data);
    }
    printf("\n");
}


// void solve() {
//     LinkList L;
//     initList(L);
//     listInsert(L,1, 3);
//     Display(L);
//     listInsert(L, 1, 5);
//     Display(L);
//     ElemType e;
//     listDelete(L, 1, e);
//     cout<<e<<endl;
//     Display(L);

//     initList(L);
//     listHeaderInsert(L);
//     Display(L);

//     initList(L);
//     listTailerInsert(L);
//     Display(L);
    
// }