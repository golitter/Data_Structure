#include <bits/stdc++.h>
#include "string.cpp"
using namespace std;

// @brief 规定字符串下标从1开始

int plain_match(SString S, SString T) {
    int i = 1, j = 1;
    while(i <= S.length && j <= T.length) {
        if(S.ch[i] == T.ch[j]) ++i, ++j;
        else {
            // 若当前子串匹配失败，则主串指针i指向下一个子串的第一个位置
            // 模式串j回到第一个位置
            i = i - j + 2;
            j = 1;
        }
    }
    return (j > T.length ? i - T.length : 0);
}
void test() {
    SString s;
    char a[] = "abcd test   ";
    strAssign(s, a);
    SString t;
    char b[] = "st";
    strAssign(t, b);
    cout<<plain_match(s, t)<<endl;
}
int main()
{
    test();
    return 0;
}