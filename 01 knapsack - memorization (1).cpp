#include <bits/stdc++.h>
using namespace std;

int knap(int wt[], int val[], int n, int W, vector<vector<int>> &dp) {
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n - 1] <= W) {
        return dp[n][W] = max(
            val[n - 1] + knap(wt, val, n - 1, W - wt[n - 1], dp),
            knap(wt, val, n - 1, W, dp)
        );
    } else {
        return dp[n][W] = knap(wt, val, n - 1, W, dp);
    }
}

int main() {
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int n = 4;
    int W = 7;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    cout << knap(wt, val, n, W, dp);
    return 0;
}