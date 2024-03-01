#include <bits/stdc++.h>
#include "./stack/link.cpp"
using namespace std;
void solve() {
    LinkStack S;
    initStack(S);
    Push(S, 1);
    Push(S, 45);
    int e;
    GetTop(S, e);
    cout<<e<<endl;
    
    Pop(S,e);
    cout<<e<<endl;
    Pop(S,e);
    cout<<e<<endl;
    Push(S, 33);
    GetTop(S, e);
    cout<<e<<endl;
    
}
int main()
{
    solve();
    return 0;
}