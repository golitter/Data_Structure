#include <bits/stdc++.h>
#include "./cued_binary_tree.cpp"
using namespace std;


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

// ***********************  后继    **************************************

// 在中序线索二叉树中找到结点p的后继结点
    /**
     * 1. 如果p的rtag == 1，那么p的后继结点是p->rchild
     * 2. 如果p的rtag == 0，那么p的后继结点是以p->rchild为根的子树中第一个被中序遍历的结点
    */
ThreadNode* NextNode(ThreadNode *p) {
    if(p->rtag == 0) {
        return FistNode(p->rchild);
    } else {
        return p->rchild;
    }
}

// 中序正向遍历线索二叉树
void InOrder(ThreadTree T) {
    for(ThreadNode *p = FistNode(T); p != NULL; p = NextNode(p)) {
        cout<<p->data<<" ";
    }
    cout<<endl;
}

// ***********************  前驱    **************************************

// 在中序线索二叉树中找到结点p的前驱结点
    /**
     * 1. 如果p的ltag == 1，那么p的前驱结点是p->lchild
     * 2. 如果p的ltag == 0，那么p的前驱结点是以p->lchild为根的子树中最后一个被中序遍历的结点
    */

// 最后一个被中序遍历的结点
ThreadNode* LastNode(ThreadNode *p) {
    while(p->rtag == 0) {
        p = p->rchild;
    }
    return p;
}

// 在中序线索二叉树中找到结点p的前驱结点
ThreadNode* PreNode(ThreadNode *p) {
    if(p->ltag == 0) {
        return LastNode(p->lchild);
    } else {
        return p->lchild;
    }
}

// 中序逆向遍历线索二叉树
void InOrderReverse(ThreadTree T) {
    for(ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p)) {
        cout<<p->data<<" ";
    }
    cout<<endl;
}
void solve() {
    ThreadTree T;
    testInitTree(T);
    creatInThread(T);

    // 中序正向遍历
    InOrder(T);
    // 中序逆向遍历
    InOrderReverse(T);

}
int main()
{
    solve(); return 0;
}