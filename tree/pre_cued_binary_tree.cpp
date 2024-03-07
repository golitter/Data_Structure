#include <bits/stdc++.h>
#include "./cued_binary_tree.cpp"
using namespace std;

void PreThread(ThreadTree &p, ThreadTree &pre) {
    if(p != NULL) {
        if(p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        // 不是前驱线索才可以
        if(p->ltag == 0) {
            PreThread(p->lchild, pre);
        }
        PreThread(p->rchild, pre);
    }
}

void creatPreThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if(T != NULL) {
        PreThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}
void solve() {
    ThreadTree T = NULL;
    testInitTree(T);
    creatPreThread(T);
    
}
int main() 
{
    solve(); return 0;
}