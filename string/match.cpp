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

    // KMP
// 个人理解：主串的i指针不回溯，模式串的j指针回溯

/**
 * 前置知识：
 * 前缀：指除最后一个字符外，字符串的所有头部子串
 * 后缀：指除第一个字符外，字符串的所有尾部子串
 * 部分匹配值则为字符串的前缀和后缀的最长相等前后缀长度
 * next[i] = presuf[i]的非平凡的最大border
*/

/**
 * 王道内容：
 * 
 * next数组的作用：当模式串的第j个字符失配时，从模式串的第next[j]的位置继续往前匹配
 * 任何模式串都一样，第2个字符不匹配时，应尝试匹配模式串的第i个字符 {
 *  next[1] = 0;
 *  next[2] = 1; 
 * }
 * 
*/

// 求next数组
void get_next(SString T, int next[]) {
    int i = 1, j = 0;
    next[i] = 0;
    while(i < T.length) {
        if(j == 0 || T.ch[i] == T.ch[j]) {
            ++i, ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}
// next算法改进
/**
 * aaaab
 * aaabaaaab
 * i = 4, j = 4时，字符a要比较3次，没有意义
*/
void get_nextval(SString T, int nextval[]) {
    int i = 1, j = 0;
    nextval[i] = 0;
    while(i < T.length) {
        if(j == 0 || T.ch[i] == T.ch[j]) {
            ++i, ++j;
            if(T.ch[i] != T.ch[j]) nextval[i] = j;
            else nextval[i] = nextval[j];
        } else j = nextval[j];
    }
}
int kmp_match(SString S, SString T) {
    int i = 1, j = 1;
    int next[T.length + 21];
    // get_next(T, next);
    get_nextval(T, next);
    while(i <= S.length && j <= T.length) {
        if(j == 0 || S.ch[i] == T.ch[j]) {
            ++i, ++j;
        } else j = next[j];
    }
    if(j > T.length) return i - T.length;
    else return 0;
}
void test2() {
    SString s;
    char a[] = "abcd test   ";
    strAssign(s, a);
    SString t;
    char b[] = "st";
    strAssign(t, b);
    cout<<kmp_match(s, t)<<endl;
}
int main()
{
    test();
    test2();
    return 0;
}