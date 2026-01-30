#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countofsubsetsum(vector<int> &nums, int n, int sum, vector<vector<int>> &dp) {
        // base cases
        dp[0][0] = 1; 

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int sum = 4;

    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

    Solution sol;
    int ans = sol.countofsubsetsum(nums, n, sum, dp);

    cout << ans << endl;
    return 0;
}
