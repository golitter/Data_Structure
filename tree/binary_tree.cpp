#include <bits/stdc++.h>
using namespace std;

#define ElemType char

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
    BiTNode() {
        lchild = NULL;
        rchild = NULL;
    }
}BiTNode, *BiTree;

void testInitBiTree(BiTree &T) {
    /**
     * A --> B
     * A --> C
     * B --> D
     * B --> E
     * C --> F
     * D --> G
     * 
     * 前序： A B D G E C F
     * 中序： D G B E A F C
     * 后序： G D E B F C A
    */

   // 用malloc不会调用构造函数，指向NULL需要自己写
    T = new BiTNode();
    T->data = 'A';
    T->lchild = new BiTNode();
    T->lchild->data = 'B';
    T->rchild = new BiTNode();
    T->rchild->data = 'C';
    T->lchild->lchild = new BiTNode();  
    T->lchild->lchild->data = 'D';
    T->lchild->rchild = new BiTNode();
    T->lchild->rchild->data = 'E';
    T->rchild->lchild = new BiTNode();
    T->rchild->lchild->data = 'F';
    T->lchild->lchild->rchild = new BiTNode();
    T->lchild->lchild->rchild->data = 'G';
}
void visit(BiTNode *T) {
    cout<<T->data<<" ";
}
void PreOrderTraverse(BiTree T) {
    if(T != NULL) {
        visit(T);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse(BiTree T) {
    if(T != NULL) {
        InOrderTraverse(T->lchild);
        visit(T);
        InOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(BiTree T) {
    if(T != NULL) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        visit(T);
    }
}

int treeDepth(BiTree T) {
    if(T == NULL) return 0;
    else {
        int l = treeDepth(T->lchild), r = treeDepth(T->rchild);
        return max(l, r) + 1;
    }
}

void levelOrder(BiTree T) {
    queue<BiTree> q;
    q.push(T);
    while(!q.empty()) {
        BiTree p = q.front(); q.pop();
        visit(p);
        if(p->lchild != NULL) q.push(p->lchild);
        if(p->rchild != NULL) q.push(p->rchild);
    }
}
void solve() {
    BiTree T;
    testInitBiTree(T);

    // 先序
    PreOrderTraverse(T);
    cout<<endl;
    // 中序
    InOrderTraverse(T);
    cout<<endl;
    // 后序
    PostOrderTraverse(T);
    cout<<endl;

    // 求深度
    cout<<"Depth:  "<<treeDepth(T)<<endl;

    // 层次遍历
    levelOrder(T);
    cout<<endl;
}
int main()
{
    solve(); return 0;
}