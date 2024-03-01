#include <bits/stdc++.h>
#include "./queue/link.cpp"
using namespace std;
void solve() {
    LinkQueue Q;
    initQueue(Q);
    for(int i = 0; i < 10; ++i) {
        EnQueue(Q, i);
    }
    while(!isEmpty(Q)) {
        int e;
        DeQueue(Q, e);
        cout<<e<<' ';
    }
    cout<<endl;
    
}
int main()
{
    solve();
    return 0;
}