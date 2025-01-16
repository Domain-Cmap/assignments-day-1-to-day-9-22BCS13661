#include<iostream>
#include<vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
    int lastNonZeroFoundAt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
        nums[i] = 0;
    }
}
int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    cout << "Output: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}