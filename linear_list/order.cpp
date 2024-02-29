#include <bits/stdc++.h>
using namespace std;
#define MaxSize 50
#define ElemType int

// 静态分配
typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;
// 动态分配
// typedef struct {
//     ElemType *data;
//     int Max_Size, length;
// }SqList;
// // 初始分配
//     // C
// // L.data = (ElemType*)malloc(sizeof(ElemType) * InitSize);
//     // CPP
// // L.data = new ElemType[InitSize];

// 初始化
void initList(SqList &L) {
    L.length = 0;
}

// 插入
bool listInsert(SqList &L, int i, ElemType e) {
    if(i < 1 || i > L.length + 1) { // 检查合法性
        // [1, length + 1 ]
        return false;
    }
    if(L.length >= MaxSize) {
        return false;
    }
    for(int j = L.length; j >= i; --j) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// 删除
bool listDelete(SqList &L, int i, ElemType &e) {
    if(i < 1 || i > L.length) {
        return false;
    }
    e = L.data[i - 1];
    for(int j = i; j < L.length; ++j) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

// 按值查找
int locateElem(SqList L, ElemType e) {
    for(int i = 0; i < L.length; ++i) {
        if(L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

// 按位置查找
ElemType getElem(SqList L, int i) {
    return L.data[i - 1];
}

// 长度
ElemType Length(SqList L) {
    return L.length;
}

// 判空
bool Empty(SqList L) {
    return L.length == 0;
}

// 展示
void Display(SqList L) {
    for(int i = 0; i < L.length; ++i) {
        cout<<L.data[i]<<' ';
    }
    cout<<'\n';
}