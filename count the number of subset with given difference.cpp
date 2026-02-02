#include <bits/stdc++.h>
using namespace std;

int countSubsetsWithSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int countSubsetsWithDiff(vector<int>& arr, int diff) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    if ((totalSum + diff) % 2 != 0 || diff > totalSum)
        return 0;

    int target = (totalSum + diff) / 2;
    return countSubsetsWithSum(arr, target);
}

int main() {
    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;

    cout << countSubsetsWithDiff(arr, diff);
    return 0;
}
