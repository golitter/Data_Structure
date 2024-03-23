/**
 * 基数排序
 * https://blog.csdn.net/qq_53414724/article/details/125015867?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522171118105116777224433338%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=171118105116777224433338&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-125015867-null-null.142^v99^pc_search_result_base3&utm_term=%E5%9F%BA%E6%95%B0%E6%8E%92%E5%BA%8F&spm=1018.2226.3001.4187
 * 
*/

// 最低位优先法(LSD)：从最低位向最高位依次按位进行排序。
// 最高位优先法(MSD)：从最高位向最低位依次按位进行排序。
// 基数排序的时间复杂度为O(d(n+r))，其中d为位数，r为基数，n为元素个数。
// 基数排序是稳定的排序算法。
// 基数排序是一种非比较排序算法，它是通过分配和收集的过程来实现排序的。
// 基数排序的核心思想是将整数按位数切割成不同的数字，然后按每个位数分别比较。

#include <bits/stdc++.h>
using namespace std;
const int N = 12;
int arr[N];
#define debug(x, y) cout << #x << " = " << x << " , " << #y << " = " << y << endl;
void randm() {
    srand(time(0));
    for(int i = 0; i < N; ++i) {
        arr[i] = rand() % 100000;
    }
}
int getSize() {
    return to_string(*max_element(arr, arr + N)).size();
}
// LSD
int getValLSD(int val, int x) {
    return val / (int)pow(10, x - 1) % 10;
}
// MSD
// int getValMSD(int val, int x) {
//     int res = val;
//     for(int i = 1; i <= x - 1; ++i) {
//         res /= 10;
//     }
//     return res % 10;
// }

queue<int> q[N];
void init() {
    for(int i = 0; i < N; ++i) {
        while(q[i].size()) q[i].pop();
    }
}
void RadixLSD(int x) {
    init();
    for(int i = 0; i < N; ++i) {
        q[getValLSD(arr[i], x)].push(arr[i]);
    }
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
        while(q[i].size()) {
            arr[cnt++] = q[i].front();
            q[i].pop();
        }
    }
}
// void RadixMSD(int x) {
//     init();
//     for(int i = 0; i < N; ++i) {
//         debug(getValMSD(arr[i], x), arr[i]);
//         q[getValMSD(arr[i], x)].push(arr[i]);
//     }
//     int cnt = 0;
//     for(int i = N - 1; i >= 0; --i) {
//         while(q[i].size()) {
//             arr[cnt++] = q[i].front();
//             q[i].pop();
//         }
//     }
// }
void RadixSortLSD() {
    int ma = getSize();
    for(int i = 1; i <= ma; ++i) {
        RadixLSD(i);
    }
}

// void RadixSortMSD() {
//     int ma = getSize();
//     for(int i = ma; i >= 1; --i) {
//         RadixMSD(i);
//     }
// }
int main()
{
    randm();
    RadixSortLSD();
    for(int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    for(int i = 1; i < N; ++i) {
        assert(arr[i] >= arr[i - 1]);
    }
    cout << endl;

    // randm();
    // RadixSortMSD();
    // for(int i = 0; i < N; ++i) {
    //     cout << arr[i] << " ";
    // }
    // for(int i = 1; i < N; ++i) {
    //     assert(arr[i] >= arr[i - 1]);
    // }
    return 0;
}
