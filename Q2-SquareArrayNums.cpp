#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int left = 0, right = n - 1;
    int pos = n - 1;
    while (left <= right) {
        if (abs(nums[left]) > abs(nums[right])) {
            result[pos--] = nums[left] * nums[left];
            left++;
        } else {
            result[pos--] = nums[right] * nums[right];
            right--;
        }
    }
    return result;
}
int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sortedSquares(nums);
    cout << "Output: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}