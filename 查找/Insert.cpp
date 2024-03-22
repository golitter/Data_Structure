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

namespace Direct {

void InsertSort(int A[], int n) {
    for(int i = 2; i < n; ++i) {
        int j = i;
        if(A[j] < A[j - 1]) {
            A[0] = A[i];
            for(j = i - 1; A[0] < A[j]; --j) {
                A[j + 1] = A[j];
            }
            A[j + 1] = A[0];
        }
    }
}
}

namespace BinaryIns {

void BinaryInsertSort(int A[], int n) {
    for(int i = 2; i < n; ++i) {
        int low = 1, high = i - 1;
        A[0] = A[i];
        while(low <= high) {
            int mid = (low + high) / 2;
            if(A[0] < A[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // 此时 low = high + 1
        for(int j = i - 1; j >= high + 1; --j) {
            A[j + 1] = A[j];
        }
        A[high + 1] = A[0];
    }
}

}

namespace Shell {

void ShellSort(int A[], int n) {
    for(int dx = n / 2; dx >= 1; dx /= 2) {
        for(int i = dx + 1; i < n; ++i) {
            if(A[i] < A[i - dx]) {
                A[0] = A[i];
                int j = i - dx;
                for(; j > 0 && A[0] < A[j]; j -= dx) {
                    A[j + dx] = A[j];
                }
                A[j + dx] = A[0];
            }
        }
    }
}

}

int main()
{
    Data::randm();
    Direct::InsertSort(Data::arr, Data::N);
    for(int i = 1; i < Data::N; ++i) {
        cout << Data::arr[i] << ' ';
    }
    for(int i = 2; i < Data::N; ++i) {
        assert(Data::arr[i] >= Data::arr[i - 1]);
    }
    cout<<'\n';

    Data::randm();
    BinaryIns::BinaryInsertSort(Data::arr, Data::N);
    for(int i = 1; i < Data::N; ++i) {
        cout << Data::arr[i] << ' ';
    }
    for(int i = 2; i < Data::N; ++i) {
        assert(Data::arr[i] >= Data::arr[i - 1]);
    }
    cout<<'\n';

    Data::randm();
    Shell::ShellSort(Data::arr, Data::N);
    for(int i = 1; i < Data::N; ++i) {
        cout << Data::arr[i] << ' ';
    }
    for(int i = 2; i < Data::N; ++i) {
        assert(Data::arr[i] >= Data::arr[i - 1]);
    }
}