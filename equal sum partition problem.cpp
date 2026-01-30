#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool knap(vector<int> &nums, int n, int sum, vector<vector<bool>> &dp){
        for(int i = 0; i <= n; i++) dp[i][0] = true;
        for(int j = 1; j <= sum; j++) dp[0][j] = false;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum += x;

        if(sum % 2 != 0) return false;

        int n = nums.size();
        sum /= 2;

        vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
        return knap(nums, n, sum, dp);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << (sol.canPartition(nums) ? "true" : "false") << endl;

    return 0;
}
