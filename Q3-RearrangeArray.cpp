#include<iostream>
#include<vector>
using namespace std;
void rearrangeArray(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        arr[i] += (arr[arr[i]] % n) * n;
    }
    for (int i = 0; i < n; i++) {
        arr[i] /= n;
    }
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    rearrangeArray(arr);
    cout << "Output: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}