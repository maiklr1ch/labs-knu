#include <iostream>

using namespace std;

void rek(int* arr, int n, int k, int index) {
    if(index == n){
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    for (int i = 1; i <= n; ++i) {
        bool valid = true;

        for (int j = 0; j < index; ++j) {
            if (abs(arr[j] - (j + 1)) > k) {
                valid = false;
                break;
            }
        }

        if (valid) {
            arr[index] = i;
            rek(arr, n, k, index + 1);
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    rek(arr, n, k, 0);
    delete[] arr;
    return 0;
}
