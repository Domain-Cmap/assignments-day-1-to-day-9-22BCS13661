#include<iostream>
using namespace std;
int sumArray(int arr[], int n) {
    if (n <= 0) {
        return 0;
    }
    return arr[n - 1] + sumArray(arr, n - 1);
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
    int sum = sumArray(arr, n);
    cout << "Sum of array elements: " << sum << endl;
    return 0;
}