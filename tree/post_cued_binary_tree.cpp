#include <bits/stdc++.h>
#include "./cued_binary_tree.cpp"
using namespace std;

void PostThread(ThreadTree &p, ThreadTree &pre) {
    if(p != NULL) {
        PostThread(p->lchild, pre);
        PostThread(p->rchild, pre);
        if(p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
    }
}

void creatPostThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if(T != NULL) {
        PostThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}
void solve() {
    ThreadTree T = NULL;
    testInitTree(T);
    creatPostThread(T);
    
}
int main()
{
    solve(); return 0;
}