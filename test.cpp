#include <bits/stdc++.h>
#include "./string/string.cpp"
using namespace std;
void solve() {
    SString s;
    char a[] = "abcd test   ";
    strAssign(s, a);
    Display(s);
    SString t;
    char b[] = "cd";
    strAssign(t, b);
    cout<<strIndex(s, t)<<endl;
    cout<<strCompare(s, t)<<endl;

    strConcat(s, s, t);
    Display(s);
}
int main()
{
    solve();
    return 0;
}