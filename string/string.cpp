#include <bits/stdc++.h>
using namespace std;
const int MaxSize = 256;

typedef struct {
    char ch[MaxSize];
    int length;
}SString;

void strAssign(SString &S, char *chars) {
    int i =  1;
    for(i = 1; chars[i - 1] != '\0'; ++i) {
        S.ch[i] = chars[i - 1];
    }
    S.length = i - 1;
}

void strCopy(SString &S, SString T) {
    for(int i = 1; i <= T.length; ++i) {
        S.ch[i] = T.ch[i];
    }
    S.length = T.length;
}

bool strEmpty(SString S) {
    return S.length == 0;
}

int strLenght(SString S) {
    return S.length;
}

int strCompare(SString S, SString T) {
    for(int i = 1; i <= S.length && i <= T.length; ++i) {
        if(S.ch[i] != T.ch[i]) return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}

void clearString(SString &S) {
    S.length = 0;
}

// S = T1 + T2
void strConcat(SString &S, SString T1, SString T2) {
    for(int i = 1; i <= T1.length; ++i) {
        S.ch[i] = T1.ch[i];
    }
    for(int i = 1; i <= T2.length; ++i) {
        S.ch[T1.length + i] = T2.ch[i];
    }
    S.length = T1.length + T2.length;
}

void strSub(SString &Sub, SString S, int pos, int len) {
    if(pos + len - 1 > S.length) return ;
    for(int i = pos; i < pos + len; ++i) {
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    Sub.length = len;
}
int strIndex(SString &S, SString T) {
    int i = 1, n = S.length, m = T.length;
    while(i <= n - m + 1) {
        SString sub;
        strSub(sub, S, i , m);
        if(strCompare(sub, T) != 0) ++i;
        else return i;
    }
    return 0;
}

void Display(SString &S) {
    cout<<"length: "<<S.length<<endl;
    for(int i = 1; i <= S.length; ++i) {
        cout<<S.ch[i];
    }
    cout<<endl;;
}