#include <bits/stdc++.h>
using namespace std;
/**
 * 数组下标一般是从零开始的
 * 矩阵下标从一开始
*/

// 对称矩阵
/**
 * a[i][j] = a[j][i];
 * 用数组进行压缩：
 * 
 * i >= j ====>    i * (i - 1) / 2 + j - 1
 * i < j ====>    j * (j - 1) / 2 + i - 1
*/
void symmetric_array() {
    int n = 5, m = 5;
    array<array<int, 6>, 6> a;
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < 6; ++j) a[i][j] = a[j][i];
    } 
    array<int, 1000> b;
    for(int i = 1; i <= 5; ++i) {
        for(int j = 1; j <= 5; ++j) {
            if(i >= j) {
                int k = i * (i - 1) / 2 + j - 1;
                b[k] = a[i][j];
            } else {
                int k = j * (j - 1) / 2 + i - 1;
                b[k] = a[i][j];
            }
        }
    }

    auto check = [&]() -> bool {
        for(int i = 1; i <= 5; ++i) {
            for(int j = 1; j <= i; ++j) {
                if(a[i][j] != b[i * (i - 1) / 2 + j - 1]) return false;
            }
        }
        return true;
    };
    cout<<( check() ? "YES" : "NO")<<'\n';

}

// 三角矩阵
/**
 * 上（下）三角区所有元素均为同一常量，下（上）不同
 * 
 * 存储 B[n(n + 1) / 2 + 1]
 * 
 * ** 下三角不同，上三角是常量
 * i >= j  ===>    i * (i - 1) / 2 + j - 1;
 * i < j   ===>    n * (n + 1) / 2
 * 
 * ** 上三角不同，上三角常量
 * i <= j  ===>  (i - 1) * (2 * n - i + 2) / 2 + j - i
 * i > j   ===> n * (n + 1) / 2
*/
void triangular_array() {
    int n = 5, m = 5;
    array<array<int, 6>, 6> a;
    array<int, 1000> b;
    for(int i = 1; i < 6; ++i) {
        for(int j = 1; j < 6; ++j) {
            if(i >= j) a[i][j] = i + j, b[ i * (i - 1) / 2 + j - 1] =a[i][j];
            else a[i][j] = -1;
        }
    } 
    b[n * (n + 1) / 2] = -1;


    for(int i = 1; i < 6; ++i) {
        for(int j = 1; j < 6; ++j) {
            if(i <= j) a[i][j] = i + j, b[ (i - 1) * ( 2 * n - i + 2) / 2 + j - i] = a[i][j];
            else a[i][j] = -1;
        }
    }
    b[n * (n + 1) / 2] = -1;
}

// 三对角矩阵
/**
 * 三对角矩阵的特点是除了主对角线和两条相邻的对角线外，其余元素均为零
 * 
 * k = 2 * i + j - 3
 * i = (k + 1) / 3 + 1 向下取整
 * j = k - 2 * i + 3
*/
void tridiagonal_array() {
    int n = 5, m = 5;
    array<array<int, 6>, 6> a;
    array<int, 1000> b;
    for(int i = 1; i < 6; ++i) {
        for(int j = 1; j < 6; ++j) {
            if(i >= j) a[i][j] = i + j, b[ i * (i - 1) / 2 + j - 1] = a[i][j];
            else a[i][j] = -1;
        }
    }     
    srand(time(0));
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < 6; ++j) {
            if(abs(j - i) <= 1) a[i][j] = rand() % 1000, b[2 * i + j - 3] = a[i][j];
            else a[i][j] = 0;
        }
    }
    for(int i = 1; i <= 5; ++i) {
        for(int j = 1; j <= 5; ++j) {
            printf("%d    ", a[i][j]);
        }
        cout<<'\n';
    }
    for(int _ = 0; _ < 10; ++_) {
        int i = (_ + 1) / 3 + 1, j = _ - 2 * i + 3;
        if(a[i][j] != b[_]) {
            cout<<"NO\n";
            break;
        }
    }
    cout<<"YES\n";
}

// 稀疏矩阵
/**
 * 三元组 i j a[i][j]
 * 
 *十字链表法
*/
int main()
{
    // 对称矩阵
    symmetric_array();

    // 三角矩阵
    triangular_array();

    // 三对角矩阵
    tridiagonal_array();
    return 0;
}