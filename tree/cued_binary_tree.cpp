#include <bits/stdc++.h>
using namespace std;

#define ElemType char

/**
 * 线索二叉树中的前驱和后继指的是对于按某顺序产生的序列中的某个元素，它的前一个元素和后一个元素
 * 例如，按照中序产生的一个序列，对于序列中的某个元素，它的前驱指的是在这个序列中它的前一个元素，后继指的是在这个序列中它的后一个元素
*/

typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    // tag == 0 ? 指针指向孩子 : 指针指向序前驱或序后继
    int ltag, rtag;
    ThreadNode() {
        lchild = NULL;
        rchild = NULL;
        ltag = 0;
        rtag = 0;
    }
}ThreadNode, *ThreadTree;

void testInitTree(ThreadTree &T) {
    T = new ThreadNode();
    T->data = 'A';
    T->lchild = new ThreadNode();
    T->lchild->data = 'B';
    T->rchild = new ThreadNode();
    T->rchild->data = 'C';
    T->lchild->lchild = new ThreadNode();  
    T->lchild->lchild->data = 'D';
    T->lchild->rchild = new ThreadNode();
    T->lchild->rchild->data = 'E';
    T->rchild->lchild = new ThreadNode();
    T->rchild->lchild->data = 'F';
    T->lchild->lchild->rchild = new ThreadNode();
    T->lchild->lchild->rchild->data = 'G';
}

// 中序线索化
void InThread(ThreadTree &p, ThreadTree &pre) {
    if(p != NULL) {
        InThread(p->lchild, pre);
        if(p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

// 按中序线索化创建线索二叉树
void creatInThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if(T != NULL) {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

// 以p为根，第一个被中序遍历的结点
ThreadNode* FistNode(ThreadNode *p) {
    while(p->ltag == 0) {
        p = p->lchild;
    }
    return p;
}

// 在中序线索二叉树中找到结点p的后继结点
ThreadNode* NextNode(ThreadNode *p) {
    if(p->rtag == 0) {
        return FistNode(p->rchild);
    } else {
        return p->rchild;
    }
}

// 中序遍历线索二叉树
void InOrder(ThreadTree T) {
    for(ThreadNode *p = FistNode(T); p != NULL; p = NextNode(p)) {
        cout<<p->data<<" ";
    }
    cout<<endl;
}
void solve() {
    ThreadTree T;
    testInitTree(T);
    creatInThread(T);
    InOrder(T);

}
int main()
{
    solve(); return 0;
}