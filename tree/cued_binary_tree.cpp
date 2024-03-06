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