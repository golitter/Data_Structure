#include <bits/stdc++.h>
using namespace std;

namespace Data {
const int N = 12;
int arr[N];
void randm() {
    iota(arr, arr + N, 0);
    random_shuffle(arr, arr + N);
}
}

namespace Bubble {

void BubbleSort(int A[], int n) {
    for(int i = 1; i < n; ++i) {
        bool flag = false;
        for(int j = n - 1; j >= i; --j) {
            if(A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = true;
            }
        }
        if(!flag) {
            break;
        }
    }
}

}

namespace Quick {

void QuickSort(int A[], int low, int high) {
    if(low >= high) {
        return ;
    }
    int i = low, j = high, pivot = A[low];
    while(i < j) {
        while(i < j && A[j] >= pivot) {
            --j;
        }
        if(i < j) {
            A[i++] = A[j];
        }
        while(i < j && A[i] < pivot) {
            ++i;
        }
        if(i < j) {
            A[j--] = A[i];
        }
    }
    A[i] = pivot;
    QuickSort(A, low, i - 1);
    QuickSort(A, i + 1, high);
}
}
int main()
{
    Data::randm();
    Bubble::BubbleSort(Data::arr, Data::N);
    for(int i = 0; i < Data::N; ++i) {
        cout << Data::arr[i] << " ";
    }
    for(int i = 1; i < Data::N; ++i) {
        assert(Data::arr[i] >= Data::arr[i - 1]);
    }
    cout<<'\n';

    Data::randm();
    Quick::QuickSort(Data::arr, 0, Data::N - 1);
    for(int i = 0; i < Data::N; ++i) {
        cout << Data::arr[i] << " ";
    }
    for(int i = 1; i < Data::N; ++i) {
        assert(Data::arr[i] >= Data::arr[i - 1]);
    }
    cout<<'\n';
    return 0;
}