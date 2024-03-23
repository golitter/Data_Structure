#include <bits/stdc++.h>
using namespace std;
const int N = 12;
int arr[N], temp[N];
void randm() {
    iota(arr, arr + N, 0);
    random_shuffle(arr, arr + N);
}

void MergeSort(int A[], int low, int high) {
    if(low >= high) {
        return ;
    }
    int mid = (low + high) >> 1;
    MergeSort(A, low, mid);
    MergeSort(A, mid + 1, high);
    int i = low, j = mid + 1, k = 0;
    while(i <= mid && j <= high) {
        if(A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else temp[k++] = A[j++];
    }
    while(i <= mid) temp[k++] = A[i++];
    while(j <= high) temp[k++] = A[j++];
    for(int i = 0; i < k; ++i) {
        A[low + i] = temp[i];
    }
}

int main()
{
    randm();
    MergeSort(arr, 0, N - 1);
    for(int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    for(int i = 1; i < N; ++i) {
        assert(arr[i] >= arr[i - 1]);
    }
    cout << endl;
    return 0;
}