// BST -- binary search tree
#include <bits/stdc++.h>
using namespace std;
using ElemType = int;

typedef struct BNode {
    ElemType data;
    struct BNode *lchild, *rchild;
}BiNode, *BiTree;

// 查找
BiNode* search(BiTree T, ElemType key) {
    while(T != NULL && key != T->data) {
        if(key < T->data) T = T->lchild;
        else T = T->rchild;
    }
    return T;
}

// 插入
int insert(BiTree &T, ElemType key) {
    if(T == NULL) {
        T = (BiTree)malloc(sizeof(BiNode));
        T->data = key;
        T->lchild = T->rchild = NULL;
        return 1;
    }
    if(k == T->data) return 0; // 二叉排序树中不能有重复的关键字
    else if(k < T->data) return insert(T->lchild, key);
    else return insert(T->rchild, key);
}

// 构造
void create(BiTree &T, ElemType arr[], int len) {
    T = NULL;
    for(int i = 0; i < len; ++i) {
        insert(T, arr[i]);
    }
}

// 删除
/**
 * 假设删除结点是z
 * 若：
 * 1. 删除结点z是叶子结点，直接删除
 *
 * 2. 只有一颗左子树或右子树，让z的子树成为z的父结点的子树
 * 
 * 3. 有两颗子树，找到z的中序前驱/后继y，用y替换z，然后删除y
 *      若找到的是中序前驱：左子树的最右边结点
 *     若找到的是中序后继：右子树的最左边结点
*/
