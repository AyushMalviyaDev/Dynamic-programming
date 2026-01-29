#include <bits/stdc++.h>
using namespace std;

int knap(int wt[], int val[], int n, int W, vector<vector<int>> &dp) {
    for(int  i = 0; i<=n;i++){
        for(int  j=0;j<=W;j++){
            dp[i][j] = 0; 
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
        if(wt[i-1]<=j){
            dp[i][j] = max(val[i-1]+dp[i-1][j - wt[i-1]], dp[i-1][j]); 
        }
        else if(wt[i-1]>j){
            dp[i][j] = dp[i-1][j]; 
        }
        }
    }
    return dp[n][W]; 
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
