#include<iostream>
using namespace std;

void selectionSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        swap(arr[maxIdx], arr[i]);
    }
}
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selectionSortDescending(arr, n);
    cout << "Sorted array in descending order: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}