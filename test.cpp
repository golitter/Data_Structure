#include <bits/stdc++.h>
#include "./linear_list/link.cpp"
using namespace std;
void solve() {
    LinkList L;
    initList(L);
    listInsert(L,1, 3);
    Display(L);
    listInsert(L, 1, 5);
    Display(L);
    ElemType e;
    listDelete(L, 1, e);
    cout<<e<<endl;
    Display(L);

    initList(L);
    listHeaderInsert(L);
    Display(L);

    initList(L);
    listTailerInsert(L);
    Display(L);
    
}
int main()
{
    solve();
    return 0;
}