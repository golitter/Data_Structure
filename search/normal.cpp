/**
 * 顺序查找
 * 二分查找
 * 分块查找
*/
#include <bits/stdc++.h>
using namespace std;
using ElemType = int;
typedef struct {
    ElemType *data;
    int tableCnt;
}SSTable;

namespace Seq {
int search(SSTable &ST, ElemType key) {
    ST.data[0] = key;
    int i;
    for(i = ST.tableCnt; ST.data[i] != key; i--);
    return i;
}
}

namespace Bin {
int search(SSTable L, ElemType key) {
    int low = 0, high = L.tableCnt - 1, mid;
    while(low < high) {
        mid = low + high >> 1;
        if(L.data[mid] == key) return mid;
        else if(L.data[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
}

int main()
{
    ;
    return 0;
}