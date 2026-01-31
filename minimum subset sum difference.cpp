// We need to minimize (Range-2*s1), this means maximize s1.
// since s1 can have values between 0 and range/2.
// so, take s1 as a knapsack of size range/2 where you need to fill maximum possible value in the knapsack.
// finally, return the answer as range-2*s1.

#include<bits/stdc++.h>
using namespace std;  

	int minDiffernce(vector<int> &arr, int n) 
	{ 
	    int range=0,i,j;
	    for(i=0; i<n; i++)
	        range+=arr[i];
	   
	    int dp[n+1][range/2+1];
	    for(i=0; i<=n; i++) dp[i][0]=0;
	    for(j=1; j<=range/2; j++) dp[0][j]=0;
	    
	    for(i=1; i<=n; i++) {
	        for(j=1; j<=range/2; j++) {
	            if(arr[i-1]<=j)
	                dp[i][j] = max(arr[i-1] + dp[i-1][j-arr[i-1]] , dp[i-1][j]);
	            else
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    return range-2*dp[n][range/2];
	}

    int main() {
    

    vector<int> nums;
    int n;
    cin >> n;

    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << minDiffernce(nums, n) << endl;
    return 0;
}
