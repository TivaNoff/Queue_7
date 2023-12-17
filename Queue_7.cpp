#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n, 0);

    int maxSum = INT_MIN;

    for (int i = 0; i < n; ++i) {
        int maxPrevSum = INT_MIN;
        for (int j = max(0, i - k); j < i; ++j) {
            maxPrevSum = max(maxPrevSum, dp[j]);
        }
        dp[i] = max(nums[i], nums[i] + maxPrevSum);
        maxSum = max(maxSum, dp[i]);
    }

    return maxSum;
}

int main() {
    // Example 1
    vector<int> nums1 = { 10, 2, -10, 5, 20 };
    int k1 = 2;
    cout << "Example 1: " << maxSubArray(nums1, k1) << endl;

    // Example 2
    vector<int> nums2 = { -1, -2, -3 };
    int k2 = 1;
    cout << "Example 2: " << maxSubArray(nums2, k2) << endl;

    // Example 3
    vector<int> nums3 = { 10, -2, -10, -5, 20 };
    int k3 = 2;
    cout << "Example 3: " << maxSubArray(nums3, k3) << endl;

    return 0;
}
